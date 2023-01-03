#include "basketmodel.h"

basketModel::basketModel(QObject *parent)
    : QAbstractListModel{parent}
{

}


int basketModel::rowCount(const QModelIndex &parent) const
{
}

QVariant basketModel::data(const QModelIndex &index, int role) const
{
}
