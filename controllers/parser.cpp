#include "parser.h"

Parser::Parser(const QByteArray & data, QObject *parent)
    : QObject{parent}
{
    parseJson(QJsonDocument::fromJson(data));
}

void Parser::parseJson(QJsonDocument jsonDocument)
{
    for (const auto & el : jsonDocument["products"].toArray())
    {
        auto object = el.toObject();

        auto name = object["name"].toString();
        auto price = object["price"].toInt();
        auto weight = object["weight"].toDouble();

        m_parsedProducts.emplace_back(name, price, weight);
    }
}

const QProductList & Parser::getProducts()
{
    return m_parsedProducts;
}
