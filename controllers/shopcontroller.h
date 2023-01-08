#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>

#include "shopmodel.h"
#include "basketmodel.h"
#include "networkhandler.h"

const QString ORDER_PATH{"/order"};
const QString SHOPLIST_PATH{"/getProducts"};
const QString DEFAULT_ADRESS{"127.0.0.1:5000"};

class ShopController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString adress READ adress WRITE setAdress NOTIFY adressChanged);
    Q_PROPERTY(QString orderInfo READ orderInfo WRITE setOrderInfo NOTIFY orderInfoChanged);
    Q_PROPERTY(QString shopListInfo READ shopListInfo WRITE setShopListInfo NOTIFY shopListInfoChanged);

public:
    explicit ShopController(QObject *parent = nullptr);

    ShopModel * getShopModel();
    BasketModel * getBasketModel();

    Q_INVOKABLE void addToBasket(qsizetype index);
    Q_INVOKABLE void removeFromBasket(qsizetype index);
    Q_INVOKABLE void makeOrder();
    Q_INVOKABLE void refreshShopList();

    QString adress() const;
    QString orderInfo() const;
    QString shopListInfo() const;
    Q_INVOKABLE void setAdress(const QString &newAdress);
    Q_INVOKABLE void setOrderInfo(const QString &newOrderInfo);
    Q_INVOKABLE void setShopListInfo(const QString &newShopListInfo);

signals:
    void adressChanged();
    void orderInfoChanged();
    void shopListInfoChanged();

private slots:
    void readProducts();
    void readOrder();
    void errorOrder(const QString & error);
    void errorShopList(const QString & error);
    void updateHandlersUrls();

private:
    NetworkHandler * m_shopListHandler;
    NetworkHandler * m_orderHandler;

    ShopModel * m_shopModel;
    BasketModel * m_basketModel;

    QString m_adress;
    QString m_orderInfo;
    QString m_shopListInfo;
};
#endif // SHOPCONTROLLER_H
