#ifndef BASKETMODEL_H
#define BASKETMODEL_H

#include <QAbstractListModel>
#include <QMap>
#include "product.h"

class BasketModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit BasketModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    void add(const Product * product);
    void remove(const Product * product);


private:
    QMap<const Product *, int> m_productCount{};

};

#endif // BASKETMODEL_H
