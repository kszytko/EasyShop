#include "shopcontroller.h"
#include "parser.h"

#include <QDebug>
#include <QLocale>
#include <QMetaEnum>

ShopController::ShopController(QObject *parent)
    : QObject{parent}, m_adress(DEFAULT_ADRESS)
{
    m_shopModel = new ShopModel();
    m_basketModel = new BasketModel();

    m_orderHandler = new NetworkHandler(m_adress, ORDER_PATH, ENCODING_FORM);
    m_shopListHandler = new NetworkHandler(m_adress, SHOPLIST_PATH, ENCODING_JSON);

    connect(m_orderHandler, &NetworkHandler::finished, this, &ShopController::readOrder);
    connect(m_shopListHandler, &NetworkHandler::finished, this, &ShopController::readProducts);

    connect(m_orderHandler, &NetworkHandler::errorOccurred, this, &ShopController::errorOrder);
    connect(m_shopListHandler, &NetworkHandler::errorOccurred, this, &ShopController::errorShopList);

    connect(this, &ShopController::adressChanged, this, &ShopController::updateHandlersUrls);

}

void ShopController::addToBasket(qsizetype index)
{
    m_basketModel->add(m_shopModel->getProduct(index));
}

void ShopController::removeFromBasket(qsizetype index)
{
    m_basketModel->remove(index);
}

void ShopController::makeOrder()
{
    m_orderHandler->send(m_basketModel->totalPrice());
}

void ShopController::refreshShopList()
{
    setShopListInfo(QString());
    m_shopModel->clear();
    m_shopListHandler->receive();
}

ShopModel *ShopController::getShopModel(){
    return m_shopModel;
}

BasketModel *ShopController::getBasketModel()
{
    return m_basketModel;
}

void ShopController::readProducts()
{
    Parser parser(m_shopListHandler->getData());
    m_shopModel->populate(parser.getProducts());

    setShopListInfo(QString("Valid"));
}

void ShopController::readOrder()
{
    auto result = m_orderHandler->getData();

    if(!result.isEmpty()){
        auto value = result.toDouble();
        const QString info{QLocale("pl_PL").toCurrencyString(value / 100)};

        setOrderInfo(info);
        m_basketModel->clear();
    };
}

void ShopController::errorOrder(const QString & error)
{
    QString info{"Error: " + error};
    setOrderInfo(info);
}

void ShopController::errorShopList(const QString & error)
{
    QString info{"Error: " + error};
    setShopListInfo(info);
}

void ShopController::updateHandlersUrls()
{
    m_orderHandler->setAdress(m_adress);
    m_shopListHandler->setAdress(m_adress);
}


QString ShopController::adress() const
{
    return m_adress;
}

void ShopController::setAdress(const QString &newAdress)
{
    if (m_adress == newAdress)
        return;
    m_adress = newAdress;
    emit adressChanged();
}

QString ShopController::orderInfo() const
{
    return m_orderInfo;
}

void ShopController::setOrderInfo(const QString &newOrderInfo)
{
    if (m_orderInfo == newOrderInfo)
        return;
    m_orderInfo = newOrderInfo;
    emit orderInfoChanged();
}

QString ShopController::shopListInfo() const
{
    return m_shopListInfo;
}

void ShopController::setShopListInfo(const QString &newShopListInfo)
{
    if (m_shopListInfo == newShopListInfo)
        return;
    m_shopListInfo = newShopListInfo;
    emit shopListInfoChanged();
}
