#include "shopcontroller.h"
#include "parser.h"

#include <QDebug>

ShopController::ShopController(DataHandler * handler, QObject *parent)
    : QObject{parent}, m_dataHandler(handler)
{
    qDebug() << connect(m_dataHandler, &DataHandler::finished, this, &ShopController::populateModel);

    m_shopModel = new ShopModel();
    m_basketModel = new BasketModel();

    m_dataHandler->downloadData();
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

int ShopController::getFullPrice()
{
    return m_basketModel->getFullPrice();
}

void ShopController::buy()
{
    qDebug() << "BUY ALL";

    //connect();
    //connect();
    m_basketModel->clear();
}

ShopModel *ShopController::getShopModel(){
    return m_shopModel;
}

BasketModel *ShopController::getBasketModel()
{
    return m_basketModel;
}

void ShopController::populateModel()
{
    Parser parser(m_dataHandler->getData());
    m_shopModel->populate(parser.getProducts());
}

