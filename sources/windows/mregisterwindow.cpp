#include "ui_registerwindow.h"
#include <QLabel>
#include "mpushbutton.h"
#include "mlineedit.h"
#include "solution.h"
#include "mregisterwindow.h"

MRegisterWindow::MRegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    sol = new Solution();
    label = ui->label;
    button = ui->button;
    name = ui->name;
    password = ui->password;

    QObject::connect(button, SIGNAL(clicked()), name, SLOT(pushString()));
    QObject::connect(button, SIGNAL(clicked(bool)), password, SLOT(pushString()));
    QObject::connect(name, SIGNAL(getString(QString,QString)), sol, SLOT(getString(QString, QString)));
    QObject::connect(password, SIGNAL(getString(QString,QString)), sol, SLOT(getString(QString,QString)));
    QObject::connect(sol, SIGNAL(checkUser(User&)), this, SLOT(checkingUser(User&)));
}

MRegisterWindow::~MRegisterWindow()
{
    delete name;
    delete password;
    delete button;
    delete sol;
    delete ui;
}

void MRegisterWindow::checkingUser(User& user)
{
    MFileWorker fW;
    auto map = fW.GetMap();
    auto un = map.find(user.name);
    if(un != map.end())
    {
        if(un.value() == user.password)
        {
            label->setText(QString::fromLocal8Bit("Вход выполнен"));
            emit openWindow();
        }
        else
            label->setText(QString::fromLocal8Bit("Неверный пароль"));
    }
    else
        label->setText(QString::fromLocal8Bit("Такого пользователя не существует"));
}

