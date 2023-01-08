#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

constexpr int TIMEOUT{5000};
const QString ENCODING_JSON{"application/json"};
const QString ENCODING_FORM{"application/x-www-form-urlencoded"};


class NetworkHandler : public QObject
{
    Q_OBJECT

public:
    explicit NetworkHandler(QString url, QString path, QString encoding, QObject *parent = nullptr);
    ~NetworkHandler();

    void receive();
    void send(int value);
    QByteArray getData();

    void setAdress(QString adress);

    QString errorToString(QNetworkReply::NetworkError code);
    
signals:
    void finished();
    void errorOccurred(const QString & error);

private slots:
    void networkReplyReadyRead();
    void networkError(QNetworkReply::NetworkError code);
    void timeoutError();

private:
    void performGET();
    void performPOST(const QByteArray & data);
    void connectNetworkReply();

private:
    QNetworkAccessManager * m_networkAccessManager;
    QNetworkReply * m_networkReply;

    QUrl m_url;
    QNetworkRequest m_request;
    QByteArray m_response;

    QTimer m_timer;
};

#endif // NETWORKHANDLER_H
