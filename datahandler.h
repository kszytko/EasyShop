#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr) : QObject{parent}{};
    virtual ~DataHandler(){};

    virtual void getProducts() = 0;
    virtual void postOrder(int totalPrice) = 0;
    virtual QByteArray getResult() = 0;

signals:
    void finishedGET();
    void finishedPOST();
};

#endif // DATAHANDLER_H
