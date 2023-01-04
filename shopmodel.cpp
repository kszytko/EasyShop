#include "shopmodel.h"

ShopModel::ShopModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int ShopModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_products.count();
}

QVariant ShopModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch(role){
    case NameRole:
        return m_products[index.row()].name();

    case PriceRole:
        return m_products[index.row()].price();

    case WeightRole:
        return m_products[index.row()].weight();

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ShopModel::roleNames() const
{
        QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[PriceRole] = "price";
        roles[WeightRole] = "weight";
        return roles;
}

void ShopModel::populate(const QProductList & products)
{
    m_products = products;
}

const Product * ShopModel::getProduct(qsizetype index)
{
    return &m_products[index];
}
