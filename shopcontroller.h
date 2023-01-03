#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>
#include <QList>
#include "product.h"

#include <QJsonArray>
#include <QJsonDocument>
#include "networkhandler.h"


#include <memory>


class ShopController : public QObject
{
    Q_OBJECT
public:
    explicit ShopController(QObject *parent = nullptr);

private:
    void readProducList(QJsonDocument json);

private slots:
    void downloadJson();

private:
    QList<std::shared_ptr<Product>> productList;

    std::shared_ptr<NetworkHandler> networkHandler;

};
#endif // SHOPCONTROLLER_H
