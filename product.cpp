#include "product.h"

Product::Product(QString name, int price, float weight): m_name(name), m_price(price), m_weight(weight){}

QString Product::name() const
{
    return m_name;
}

int Product::price() const
{
    return m_price;
}

double Product::weight() const
{
    return m_weight;
}
