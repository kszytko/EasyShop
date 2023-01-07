#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "datahandler.h"

class NetworkHandler : public DataHandler
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged);

public:
    explicit NetworkHandler(QString url, QString productEndpoint, QString orderEndpoint, QObject *parent = nullptr);
    ~NetworkHandler() override;

    void getProducts() override;
    void postOrder(int totalPrice) override;

    QByteArray getResult() override;

    QString url() const;
    void setUrl(const QString &newUrl);


public slots:
    void updateEndpoints();

private slots:
    void networkReplyReadyReadGET();
    void networkReplyReadyReadPOST();

signals:
    void urlChanged();

private:
    void performGET(const QUrl & url);
    void performPOST(const QUrl & url, const QByteArray & data);
    void networkReplyReadyRead();

    std::unique_ptr<QNetworkAccessManager> m_networkAccessManager;
    std::shared_ptr<QNetworkReply> m_networkReply;

    QByteArray m_response;

    QString m_url;
    QUrl m_productsEndpoint;
    QUrl m_orderEndpoint;
};

#endif // NETWORKHANDLER_H
