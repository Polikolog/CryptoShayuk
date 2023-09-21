#ifndef MLOBBYWINDOW_H
#define MLOBBYWINDOW_H

#include <QMainWindow>

class MPushButton;
class MFirstPage;
class MSecondPage;
class MInfoPage;

namespace Ui {
class MLobbyWindow;
}

class MLobbyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MLobbyWindow(QWidget *parent = nullptr);
    ~MLobbyWindow();

public slots:
    void openFirstPage();
    void openSecondPage();
    void openInfoPage();

private slots:
    void closeApp();

private:
    MPushButton *exitB;
    MPushButton *firstB;
    MPushButton *secondB;
    MPushButton *infoB;
    MPushButton *clearB;
    MFirstPage *firstW;
    MSecondPage *secondW;
    MInfoPage *infoW;
    Ui::MLobbyWindow *ui;
};

#endif // MLOBBYWINDOW_H
