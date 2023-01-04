#ifndef BASKETMODEL_H
#define BASKETMODEL_H

#include <QAbstractListModel>
#include <QMap>

#include "product.h"

class BasketModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ModelRoles {
        NameRole = Qt::UserRole + 1,
        AmountRole,
        PriceRole,
    };

    explicit BasketModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void add(Product * product);
    void remove(qsizetype index);
    void clear();

    int getFullPrice();

private:
    Product * getProduct(int index) const;
    int getAmount(int index) const;

private:
    QMap<Product *, int> m_productCount{};

};

#endif // BASKETMODEL_H
