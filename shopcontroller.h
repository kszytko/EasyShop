#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>

#include "datahandler.h"
#include "shopmodel.h"
#include "basketmodel.h"


class ShopController : public QObject
{
    Q_OBJECT

public:
    explicit ShopController(DataHandler * handler, QObject *parent = nullptr);

    Q_INVOKABLE void addToBasket(qsizetype index);
    Q_INVOKABLE void removeFromBasket(qsizetype index);
    Q_INVOKABLE int getFullPrice();
    Q_INVOKABLE void buy();

    ShopModel * getShopModel();
    BasketModel * getBasketModel();

private slots:
    void populateModel();

private:
    DataHandler * m_dataHandler;
    ShopModel * m_shopModel;
    BasketModel * m_basketModel;
};
#endif // SHOPCONTROLLER_H
