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
    explicit NetworkHandler(QString dataEndpoint_, QObject *parent = nullptr);
    ~NetworkHandler();

    void downloadData();
    QJsonDocument getParsedJson();

public slots:
    void networkReplyReadyRead();

signals:
    void dataParsed();

private:
    void performGET(const QString & url);
    void parseResponse(const QByteArray & response);

    QJsonDocument m_parsedReply;

    std::unique_ptr<QNetworkAccessManager> m_networkAccessManager;
    std::shared_ptr<QNetworkReply> m_networkReply;

    QString dataEndpoint{};
};

#endif // NETWORKHANDLER_H
