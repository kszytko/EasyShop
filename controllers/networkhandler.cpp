#include "networkhandler.h"
#include <QMetaEnum>

NetworkHandler::NetworkHandler(QString url, QString path, QString encoding, QObject *parent)
    : QObject{parent}
{
    m_networkAccessManager = new QNetworkAccessManager(parent);

    m_url.setScheme("http");
    m_url.setAuthority(url);
    m_url.setPath(path);

    m_request.setUrl(m_url);
    m_request.setHeader( QNetworkRequest::ContentTypeHeader, encoding);

    m_timer.setSingleShot(true);
}

NetworkHandler::~NetworkHandler()
{
    m_networkAccessManager->deleteLater();
}

void NetworkHandler::receive()
{
    performGET();
}

void NetworkHandler::send(int value)
{
    QByteArray data{"value=" + QString::number(value).toUtf8()};
    performPOST(data);
}

void NetworkHandler::performGET()
{
    m_timer.start(TIMEOUT);
    m_networkReply = m_networkAccessManager->get(m_request);
    connectNetworkReply();
}

void NetworkHandler::performPOST(const QByteArray & data)
{
    m_timer.start(TIMEOUT);
    m_networkReply = m_networkAccessManager->post(m_request, data);
    connectNetworkReply();
}

void NetworkHandler::connectNetworkReply()
{
    connect(m_networkReply, &QNetworkReply::finished, this, &NetworkHandler::networkReplyReadyRead);
    connect(m_networkReply, &QNetworkReply::errorOccurred, this, &NetworkHandler::networkError);
    connect(&m_timer, &QTimer::timeout, this, &NetworkHandler::timeoutError);
}

QByteArray NetworkHandler::getData()
{
    return m_response;
}

void NetworkHandler::setAdress(QString adress)
{
    m_url.setAuthority(adress);
    m_request.setUrl(m_url);
}

void NetworkHandler::networkReplyReadyRead()
{
    if(m_networkReply->error() != QNetworkReply::NoError){
        return;
    }

    m_response = m_networkReply->readAll();
    m_networkReply->deleteLater();

    m_timer.stop();
    emit finished();
}

void NetworkHandler::networkError(QNetworkReply::NetworkError code)
{
    Q_UNUSED(code);
    m_timer.stop();    
    emit errorOccurred(m_networkReply->errorString());
}

void NetworkHandler::timeoutError()
{
    m_networkReply->abort();
    emit errorOccurred(QString("Timeout"));
}
