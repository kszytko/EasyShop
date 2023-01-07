#include "shopcontroller.h"
#include "parser.h"

#include <QDebug>

ShopController::ShopController(DataHandler * handler, QObject *parent)
    : QObject{parent}, m_dataHandler(handler)
{
    m_shopModel = new ShopModel();
    m_basketModel = new BasketModel();

    qDebug() << connect(m_dataHandler, &DataHandler::finishedGET, this, &ShopController::readProducts);
    qDebug() << connect(m_dataHandler, &DataHandler::finishedPOST, this, &ShopController::readOrder);
}

void ShopController::addToBasket(qsizetype index)
{
    qDebug() << "Adding: " << index;
    m_basketModel->add(m_shopModel->getProduct(index));
    qDebug() << "Added: " << index;
}

void ShopController::removeFromBasket(qsizetype index)
{
    qDebug() << "Removing: " << index;
    m_basketModel->remove(index);
    qDebug() << "Removed: " << index;
}

void ShopController::buy()
{
    qDebug() << "BUY ALL";

    m_dataHandler->postOrder(m_basketModel->totalPrice());
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
    qDebug() << "ReadProducts";
    Parser parser(m_dataHandler->getResult());
    m_shopModel->populate(parser.getProducts());
}

void ShopController::readOrder()
{
    qDebug() << "ReadOrder";
    auto result = m_dataHandler->getResult();
    if(!result.isEmpty()){
        setOrderPrice(result.toInt());
        m_basketModel->clear();
    } else {
        setOrderPrice(0);
    }
}


int ShopController::orderPrice() const
{
    return m_orderPrice;
}

void ShopController::setOrderPrice(int newOrderPrice)
{
    if (m_orderPrice == newOrderPrice)
        return;
    m_orderPrice = newOrderPrice;
    emit orderPriceChanged();
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
