#ifndef MFILEWORKER_H
#define MFILEWORKER_H

#include <QFile>
#include <QDebug>
#include <QMap>

class MFileWorker
{
public:
    MFileWorker();
    ~MFileWorker();

    bool GetUserData();
    const QMap<QString, QString> &GetMap();

private:
    QFile *file;
    QString buffer;
    QMap<QString, QString> map;
};

#endif // MFILEWORKER_H
