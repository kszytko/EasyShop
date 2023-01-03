#ifndef SHOPMODEL_H
#define SHOPMODEL_H

#include <QAbstractListModel>

class shopModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit shopModel(QObject *parent = nullptr);

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // SHOPMODEL_H
