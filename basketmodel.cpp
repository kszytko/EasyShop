#include "basketmodel.h"

BasketModel::BasketModel(QObject *parent)
    : QAbstractListModel{parent}
{

}


int BasketModel::rowCount(const QModelIndex &parent) const
{
    return m_productCount.size();
}

QVariant BasketModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch(role){

    default:
        return QVariant();
    }
}

void BasketModel::add(const Product * product)
{
    ++m_productCount[product];
}
S
void BasketModel::remove(const Product * product)
{
    m_productCount.remove(product);
}
