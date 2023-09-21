#ifndef MASTERWINDOW_H
#define MASTERWINDOW_H

#include <QWidget>
class MRegisterWindow;
class MLobbyWindow;

class MasterWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MasterWindow(QWidget *parent = nullptr);
    ~MasterWindow();

public slots:
    void openLobbyWin();

private:
    MRegisterWindow *regWin;
    MLobbyWindow *lobWin;
};

#endif // MASTERWINDOW_H
