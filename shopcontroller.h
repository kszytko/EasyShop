#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>

#include "networkhandler.h"
#include "filehandler.h"

#include "shopmodel.h"


class ShopController : public QObject
{
    Q_OBJECT

public:
    explicit ShopController(QObject *parent = nullptr);
    ShopController(QString fileName, QObject *parent = nullptr);

    Q_INVOKABLE void addToBasket(int index);
    ShopModel * getShopModel();

private slots:
    void populateModel();

private:
    NetworkHandler * m_networkHandler;
    FileHandler * m_fileHandler;

    ShopModel * m_shopModel;


};
#endif // SHOPCONTROLLER_H
