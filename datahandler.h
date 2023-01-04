#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr) : QObject{parent}{};
    virtual ~DataHandler(){};

    virtual void downloadData() = 0;
    virtual QByteArray getData() = 0;

signals:
    void finished();
};

#endif // DATAHANDLER_H
