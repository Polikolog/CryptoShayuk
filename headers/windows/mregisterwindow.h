#ifndef MREGISTERWINDOW_H
#define MREGISTERWINDOW_H

#include <QMainWindow>
class QLabel;
class MLineEdit;
class Solution;
class MPushButton;
class User;

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterWindow; }
QT_END_NAMESPACE

class MRegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    MRegisterWindow(QWidget *parent = nullptr);
    ~MRegisterWindow();

public slots:
    void checkingUser(User&);

signals:
    void openWindow();

private:
    QLabel *label;
    MPushButton *button;
    MLineEdit *name;
    MLineEdit *password;
    Solution *sol;
    Ui::RegisterWindow *ui;
};

#endif // MREGISTERWINDOW_H
