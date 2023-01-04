#include "shopcontroller.h"
#include "parser.h"

#include <QDebug>

ShopController::ShopController(DataHandler * handler, QObject *parent)
    : QObject{parent}, m_dataHandler(handler)
{
    qDebug() << connect(m_dataHandler, &DataHandler::finished, this, &ShopController::populateModel);

    m_shopModel = new ShopModel();
    m_dataHandler->downloadData();
}

void ShopController::addToBasket(qsizetype index)
{
    m_basketModel->add(m_shopModel->getProduct(index));
    qDebug() << "Adding: " << index;
}

void ShopController::removeFromBasket(qsizetype index)
{
    m_basketModel->remove(m_shopModel->getProduct(index));
    qDebug() << "Removed: " << index;
}

ShopModel *ShopController::getShopModel(){
    return m_shopModel;
}

void ShopController::populateModel()
{
    Parser parser(m_dataHandler->getData());
    m_shopModel->populate(parser.getProducts());
}

