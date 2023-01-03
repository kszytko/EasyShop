#include "shopcontroller.h"


ShopController::ShopController(QObject *parent)
    : QObject{parent}
{
    networkHandler = std::make_shared<NetworkHandler>("http://127.0.0.1:5000/getProducts");
    networkHandler->downloadData();

    connect(networkHandler.get(), &NetworkHandler::dataParsed, this, &ShopController::downloadJson);


}

void ShopController::readProducList(QJsonDocument json){
    QJsonArray data = json["products"].toArray();

    for (const auto& el : data)
    {

        productList.push_back(std::make_shared<Product>(el.toObject()));
    }



}

void ShopController::downloadJson()
{
    readProducList(networkHandler->getParsedJson());
}
