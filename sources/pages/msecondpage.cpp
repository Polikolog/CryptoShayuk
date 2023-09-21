#include "ui_mlobbywindow.h"
#include "msecondpage.h"
#include <QFile>
#include <QString>

MSecondPage::MSecondPage(QWidget *parent)
    :QWidget{parent}
{

}

void MSecondPage::SetUi(Ui::MLobbyWindow *tui)
{
    ui = tui;
    QObject::connect(ui->Hashing, SIGNAL(clicked()), this, SLOT(Hashing()));
}

void MSecondPage::setFile(QFile * mfile)
{
    file = mfile;
}

void MSecondPage::Hashing()
{
    QString hash = HTiger::encrypt(ui->textRef->toPlainText(), ui->textKey->toPlainText().toLongLong(nullptr, 16), ui->textEdit);
    ui->textEdit->append("\n Hash: " + hash);
    ui->textEdit->append(QString("\n"));
    ui->textRef->append("\n Hash: " + hash);
}


void MSecondPage::ClearTextFields()
{
    ui->textEdit->clear();
}
