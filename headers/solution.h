#ifndef SOLUTION_H
#define SOLUTION_H

#include <QObject>
#include "user.h"
#include "mfileworker.h"

class Solution : public QObject
{
    Q_OBJECT
public:
    Solution(QWidget* parent = nullptr);

public slots:
    void getString(QString, QString);

signals:
    void checkUser(User&);

private:
    User user;
};

#endif // SOLUTION_H
