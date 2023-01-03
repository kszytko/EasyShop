#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>

class Product
{
public:
    Product(QString name, int price, float weight);;
    explicit Product(const QJsonObject& json);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged);
    Q_PROPERTY(int price READ price WRITE setPrice NOTIFY priceChanged);
    Q_PROPERTY(double weight READ weight WRITE setWeight NOTIFY weightChanged)

    QString name() const;
    int price() const;
    double weight() const;

    void setName(const QString &newName);
    void setPrice(int newPrice);
    void setWeight(double newWeight);

signals:
    void nameChanged();
    void priceChanged();
    void weightChanged();

private:
    QString m_name;
    int m_price;
    double m_weight;
};

#endif // PRODUCT_H
