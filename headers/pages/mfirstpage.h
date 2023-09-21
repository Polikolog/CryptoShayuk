#ifndef MFIRSTPAGE_H
#define MFIRSTPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextEdit>
namespace Ui {
class MLobbyWindow;
}

class MFirstPage : public QWidget
{
    Q_OBJECT
public:
    MFirstPage(QWidget *parent = nullptr);
    void SetUi(Ui::MLobbyWindow *tui);

signals:
    void setFile(QFile*);

public slots:
    void openFileDialog();
    void saveChangedFile();
    void closeChangedFile();
    void ClearTextField();

private:
    QString fileName;
    Ui::MLobbyWindow *ui;
};

#endif // MFIRSTPAGE_H
