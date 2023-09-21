#include "mlobbywindow.h"
#include "ui_mlobbywindow.h"
#include "ui_ThirdPage.h"
#include "mpushbutton.h"
#include "mfirstpage.h"
#include "msecondpage.h"
#include "minfopage.h"

MLobbyWindow::MLobbyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MLobbyWindow)
{
    ui->setupUi(this);

    exitB = ui->exit;

    firstB = ui->first;
    secondB = ui->second;
    infoB = ui->info;

    infoW = ui->infoPage;
    infoW->SetUi(ui);
    infoW->show();

    firstW = ui->firstPage;
    firstW->SetUi(ui);
    firstW->hide();

    secondW = ui->secondPage;
    secondW->SetUi(ui);
    secondW->hide();

    clearB = ui->clear;

    QObject::connect(firstB, SIGNAL(clicked()), this, SLOT(openFirstPage()));
    QObject::connect(secondB, SIGNAL(clicked()), this, SLOT(openSecondPage()));
    QObject::connect(infoB, SIGNAL(clicked()), this, SLOT(openInfoPage()));
    QObject::connect(clearB, SIGNAL(clicked()), firstW, SLOT(ClearTextField()));
    QObject::connect(clearB, SIGNAL(clicked()), secondW, SLOT(ClearTextFields()));
    QObject::connect(exitB, SIGNAL(clicked()), this, SLOT(closeApp()));
}

MLobbyWindow::~MLobbyWindow()
{
    delete ui;
}

void MLobbyWindow::openFirstPage()
{
    qDebug() << "Button click";
    if(!firstW->isEnabled())
    {
        secondW->setEnabled(false);
        infoW->setEnabled(false);
        firstW->show();
        firstW->setEnabled(true);
        secondW->hide();
        infoW->hide();
        qDebug() << "Window open";
    }
}

void MLobbyWindow::openSecondPage()
{
    if(!secondW->isEnabled())
    {
        secondW->show();
        firstW->setEnabled(false);
        infoW->setEnabled(false);
        secondW->setEnabled(true);
        firstW->hide();
        infoW->hide();
    }
}

void MLobbyWindow::openInfoPage()
{
    if(!infoW->isEnabled())
    {
        secondW->hide();
        firstW->setEnabled(false);
        infoW->setEnabled(true);
        secondW->setEnabled(false);
        firstW->hide();
        infoW->show();
    }
}

void MLobbyWindow::closeApp()
{
    qApp->exit();
}
