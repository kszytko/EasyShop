#ifndef SHOPMODEL_H
#define SHOPMODEL_H

#include <QAbstractListModel>
#include "product.h"

class ShopModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AnimalRoles {
        NameRole = Qt::UserRole + 1,
        PriceRole,
        WeightRole
    };

    explicit ShopModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void populate(const QProductList & products);
    const Product & getProduct(qsizetype index);

private:
    QProductList m_products;

};

#endif // SHOPMODEL_H
