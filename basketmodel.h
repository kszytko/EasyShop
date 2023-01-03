#ifndef BASKETMODEL_H
#define BASKETMODEL_H

#include <QAbstractListModel>

class basketModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit basketModel(QObject *parent = nullptr);

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // BASKETMODEL_H
