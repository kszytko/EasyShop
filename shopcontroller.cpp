#include "shopcontroller.h"
#include "parser.h"

#include <QDebug>

ShopController::ShopController(QObject *parent)
    : QObject{parent}
{
    m_shopModel = new ShopModel();
    m_networkHandler = new NetworkHandler("http://127.0.0.1:5000/getProducts");
    m_networkHandler->downloadData();
    connect(m_networkHandler, &NetworkHandler::finished, this, &ShopController::populateModel);
}

ShopController::ShopController(QString fileName, QObject *parent)
    : QObject{parent}
{
    qDebug() << "start here";
    m_shopModel = new ShopModel();
    m_fileHandler = new FileHandler(fileName);
    m_fileHandler->downloadData();
    qDebug() << connect(m_fileHandler, &FileHandler::finished, this, &ShopController::populateModel);
}

void ShopController::addToBasket(int index)
{
    //basketModel->append(shopModel.getProduct(index));
    qDebug() << "Adding: " << index;
}

ShopModel *ShopController::getShopModel(){
    return m_shopModel;
}

void ShopController::populateModel()
{
    qDebug() << "Read: ";
    //Parser parser(m_networkHandler->getData());
    Parser parser(m_fileHandler->getData());
    m_shopModel->populate(parser.getProducts());
}

