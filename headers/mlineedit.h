#ifndef MLINEEDIT_H
#define MLINEEDIT_H

#include <QLineEdit>

class MLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MLineEdit(QWidget* parent = nullptr);

public slots:
    void pushString();

signals:
    void getString(QString, QString);
};

#endif // MLINEEDIT_H
