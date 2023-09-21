#ifndef MSECONDPAGE_H
#define MSECONDPAGE_H

#include <QWidget>
#include "htiger.h"

class QString;
class QFile;

namespace Ui {
class MLobbyWindow;
}

class MSecondPage : public QWidget
{
    Q_OBJECT
public:
    MSecondPage(QWidget *parent = nullptr);
    void SetUi(Ui::MLobbyWindow *tui);

public slots:
    void setFile(QFile*);
    void Hashing();
    void ClearTextFields();

private:
    uint64_t key = 0x0123456789abcdefULL;
    QFile *file;
    Ui::MLobbyWindow *ui;
};

#endif // MSECONDPAGE_H
