#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>

#include "product.h"

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(const QByteArray & data, QObject *parent = nullptr);
    const QProductList & getProducts();

private:
    void parseJson(QJsonDocument json);

private:
    QJsonDocument m_jsonDocument;
    QProductList m_parsedProducts;
};

#endif // PARSER_H
