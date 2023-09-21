#include <QApplication>
#include <QDebug>
#include <QTextCodec>
#include "masterwindow.h"

int main(int argc, char *argv[])
{

    QLocale::setDefault(QLocale::c());
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);

    MasterWindow *master = new MasterWindow();

    return a.exec();
}
