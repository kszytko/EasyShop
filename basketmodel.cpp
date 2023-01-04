#include <QMapIterator>
#include "basketmodel.h"

BasketModel::BasketModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int BasketModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_productCount.size();
}

QVariant BasketModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch(role){
    case NameRole:
        return getProduct(index.row())->name();
    case AmountRole:
        return getAmount(index.row());
    case PriceRole:
        return getProduct(index.row())->price();
    default:
        return QVariant();
    }
}

void BasketModel::add(Product * product)
{
    ++m_productCount[product];
}

void BasketModel::remove(qsizetype index)
{
    beginRemoveRows(QModelIndex(),index, index);

    auto product = m_productCount.keys().at(index);
    m_productCount.remove(product);

    endRemoveRows();
}

void BasketModel::clear()
{
    beginRemoveRows(QModelIndex(),0, m_productCount.size());

    m_productCount.clear();

    endRemoveRows();
}

int BasketModel::getFullPrice()
{
    int sum = 0;

    QMapIterator<Product *, int> i(m_productCount);
    while (i.hasNext()) {
        i.next();

        sum += i.key()->price() * i.value();
    }

    return sum;
}

Product * BasketModel::getProduct(int index) const
{
    return m_productCount.keys().at(index);
}

int BasketModel::getAmount(int index) const
{
    return m_productCount.values().at(index);
}


QHash<int, QByteArray> BasketModel::roleNames() const
{
        QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[PriceRole] = "price";
        roles[AmountRole] = "amount";
        return roles;
}
