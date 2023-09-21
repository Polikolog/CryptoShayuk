#include "masterwindow.h"
#include "mregisterwindow.h"
#include "mlobbywindow.h"

MasterWindow::MasterWindow(QWidget *parent)
    : QWidget{parent}
{
    //regWin = new MRegisterWindow();

    //QObject::connect(regWin, SIGNAL(openWindow()), this, SLOT(openLobbyWin()));

    //regWin->show();

    lobWin = new MLobbyWindow();
    lobWin->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    lobWin->setWindowTitle("Tiger-Hash");
    QIcon icon(":img/resources/icon.png");
    lobWin->setWindowIcon(icon);
    lobWin->show();
}

MasterWindow::~MasterWindow()
{
    delete lobWin;
    delete regWin;
}

void MasterWindow::openLobbyWin()
{
    regWin->close();
    delete regWin;
    lobWin = new MLobbyWindow();
    lobWin->show();
}


