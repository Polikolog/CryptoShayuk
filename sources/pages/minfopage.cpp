#include "minfopage.h"
#include "ui_mlobbywindow.h"

MInfoPage::MInfoPage(QWidget *parent)
    : QWidget{parent}
{}

void MInfoPage::SetUi(Ui::MLobbyWindow *tui)
{
    ui = tui;
}


