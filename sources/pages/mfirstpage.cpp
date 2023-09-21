#include "mfirstpage.h"
#include "ui_mlobbywindow.h"

MFirstPage::MFirstPage(QWidget *parent)
    : QWidget{parent}
{
}

void MFirstPage::SetUi(Ui::MLobbyWindow *tui)
{
    ui = tui;

    QObject::connect(ui->openFile, SIGNAL(clicked()), this, SLOT(openFileDialog()));
    QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveChangedFile()));
}

void MFirstPage::openFileDialog()
{
    fileName = QFileDialog::getOpenFileName(this, "Open File TXT", "D:\\", "Text files (*.txt)");

    QFile file(fileName);

    file.open(QIODeviceBase::ReadOnly);

    QString buffer = file.read(file.size());

    ui->textRef->setText(buffer);

    file.close();

}

void MFirstPage::saveChangedFile()
{
    QFile file(fileName);

    file.open(QIODeviceBase::WriteOnly);

    file.write(ui->textRef->toPlainText().toStdString().c_str());

    file.close();

    ui->textRef->clear();
}

void MFirstPage::closeChangedFile()
{

}

void MFirstPage::ClearTextField()
{
    ui->textKey->clear();
    ui->textRef->clear();
}
