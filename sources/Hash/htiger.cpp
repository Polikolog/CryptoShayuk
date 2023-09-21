#include "htiger.h"
#include <QDebug>
#include <QString>
#include <QTextEdit>

namespace HTiger
{
    QString encrypt(QString message, uint64_t key, QTextEdit *field)
    {
        setlocale(LC_ALL, " ");
        field->append("Input message:" + message + "\tKey:" + QString::number(key));

        int length = message.length();
        int padding = BLOCK_SIZE - (length % BLOCK_SIZE);
        message += QString(padding, QChar(padding));

        qDebug() << "Reducing the message to a length multiple of the block size: " << message;
        field->append("Reducing the message to a length multiple of the block size: " + message);

        uint64_t a = key ^ 0x736f6d6570736575ull;
        uint64_t b = key ^ 0x646f72616e646f6dull;
        uint64_t c = key ^ 0x6c7967656e657261ull;

        qDebug() << "Initial hash value: a = " << a << "\tb = " << b << "\tc = " << c;
        field->append("Initial hash value: a = " + QString::number(a) + "\tb = " + QString::number(b) + "\tc = " + QString::number(c));

        for (int i = 0; i < length; i += BLOCK_SIZE) {
            uint64_t block[8] = {0};

            for (int j = 0; j < BLOCK_SIZE; j += 8) {
                block[j/8] = ((uint64_t) message[i+j].unicode() << 56) |
                             ((uint64_t) message[i+j+1].unicode() << 48) |
                             ((uint64_t) message[i+j+2].unicode() << 40) |
                             ((uint64_t) message[i+j+3].unicode() << 32) |
                             ((uint64_t) message[i+j+4].unicode() << 24) |
                             ((uint64_t) message[i+j+5].unicode() << 16) |
                             ((uint64_t) message[i+j+6].unicode() << 8) |
                             ((uint64_t) message[i+j+7].unicode());
            }

            qDebug() << "Block before rounds: ";
            for (int k = 0; k < 8; k++)
            {
                qDebug()<< std::hex << block[k];
            }

            field->append("Block after rounds: ");
            qDebug() << "Block after rounds";

            //Main block
            for (int j = 0; j < 8; j++) {
                c ^= block[j];

                uint64_t tmp = a;
                a = c ^ (a << 1);
                c = b + (c << 1);
                b = tmp ^ (b >> 1);
                a ^= ROUND_CONSTANTS[j];
                b ^= SBOX[0][a & 0xff] ^
                     SBOX[1][(a >> 16) & 0xff] ^
                     SBOX[2][(a >> 32) & 0xff] ^
                     SBOX[3][(a >> 48) & 0xff];
                c ^= SBOX[3][(b >> 48) & 0xff] ^
                     SBOX[2][(b >> 32) & 0xff] ^
                     SBOX[1][(b >> 16) & 0xff] ^
                     SBOX[0][b & 0xff];

                QString round_hash = QString("%1%2%3")
                            .arg(a, 16, 16, QChar('0'))
                            .arg(b, 16, 16, QChar('0'))
                            .arg(c, 16, 16, QChar('0'));
                        field->append("Round " + QString::number(j+1) + " hash: " + round_hash);
                        qDebug() << "Round" << j+1 << "hash:" << round_hash;

            }

            a ^= key;
            b ^= key;
            c ^= key;

            key = c;
        }

        QString hash = QString("%1%2%3")
            .arg(a, 16, 16, QChar('0'))
            .arg(b, 16, 16, QChar('0'))
            .arg(c, 16, 16, QChar('0'));

        return hash;
    }
}
