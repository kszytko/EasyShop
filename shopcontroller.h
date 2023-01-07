#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>

#include "datahandler.h"
#include "shopmodel.h"
#include "basketmodel.h"


class ShopController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int orderPrice READ orderPrice WRITE setOrderPrice NOTIFY orderPriceChanged);
    Q_PROPERTY(QString adress READ adress WRITE setAdress NOTIFY adressChanged);

public:
    explicit ShopController(DataHandler * handler, QObject *parent = nullptr);

    Q_INVOKABLE void addToBasket(qsizetype index);
    Q_INVOKABLE void removeFromBasket(qsizetype index);
    Q_INVOKABLE void buy();

    ShopModel * getShopModel();
    BasketModel * getBasketModel();

    int orderPrice() const;
    void setOrderPrice(int newOrderPrice);

    QString adress() const;
    void setAdress(const QString &newAdress);

signals:
    void orderPriceChanged();

    void adressChanged();

private slots:
    void readProducts();
    void readOrder();

private:
    DataHandler * m_dataHandler;
    ShopModel * m_shopModel;
    BasketModel * m_basketModel;

    int m_orderPrice;
    QString m_adress;
};
#endif // SHOPCONTROLLER_H
