#ifndef MINFOPAGE_H
#define MINFOPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextEdit>
namespace Ui {
class MLobbyWindow;
}

class MInfoPage : public QWidget
{
    Q_OBJECT
public:
    MInfoPage(QWidget *parent = nullptr);
    void SetUi(Ui::MLobbyWindow *tui);

private:
    Ui::MLobbyWindow *ui;
};

#endif // MFIRSTPAGE_H
