#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>

class Product
{
public:
    explicit Product(QString name, int price, float weight);;

    QString name() const;
    int price() const;
    double weight() const;

private:
    QString m_name;
    int m_price;
    double m_weight;
};

using QProductList = QList<Product>;


#endif // PRODUCT_H
