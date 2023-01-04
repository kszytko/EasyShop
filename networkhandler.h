#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

class NetworkHandler : public QObject
{
    Q_OBJECT
public:
    explicit NetworkHandler(QString endpoint, QObject *parent = nullptr);
    ~NetworkHandler();

    void downloadData();
    QByteArray getData();

public slots:
    void networkReplyReadyRead();

signals:
    void finished();

private:
    void performGET(const QString & url);

    std::unique_ptr<QNetworkAccessManager> m_networkAccessManager;
    std::shared_ptr<QNetworkReply> m_networkReply;

    QString m_endpoint;
    QByteArray m_response;
};

#endif // NETWORKHANDLER_H
