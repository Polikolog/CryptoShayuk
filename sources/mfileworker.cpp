#include "mfileworker.h"

MFileWorker::MFileWorker()
{
    file = new QFile("D:\\Tch\\QT\\QEx2\\user.txt");
    if(file->isOpen())
    {
        qDebug() << "File user.txt is Open";
    }
    if(!GetUserData())
        qDebug() << "File does not open";
}

bool MFileWorker::GetUserData()
{
    if(!file->open(QIODevice::OpenModeFlag::ReadOnly))
        return false;

    buffer = file->read(file->size());

    auto strings = buffer.split('\n');

    for(auto str : strings)
    {
        auto pair = str.split(' ');
        map.insert(pair[0], pair[1]);
    }
    return true;
}

MFileWorker::~MFileWorker()
{
    file->close();
    delete file;
}

const QMap<QString, QString> &MFileWorker::GetMap()
{
    return map;
}
