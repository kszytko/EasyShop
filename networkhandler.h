#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

#include "datahandler.h"

class NetworkHandler : public DataHandler
{
    Q_OBJECT
public:
    explicit NetworkHandler(QString endpoint, QObject *parent = nullptr);
    ~NetworkHandler() override;

    void downloadData() override;
    QByteArray getData() override;

public slots:
    void networkReplyReadyRead();

private:
    void performGET(const QString & url);

    std::unique_ptr<QNetworkAccessManager> m_networkAccessManager;
    std::shared_ptr<QNetworkReply> m_networkReply;

    QString m_endpoint;
    QByteArray m_response;
};

#endif // NETWORKHANDLER_H
