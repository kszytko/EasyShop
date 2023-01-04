#include "networkhandler.h"


NetworkHandler::NetworkHandler(QString endpoint, QObject *parent)
    : QObject{parent}, m_endpoint(endpoint)
{
    m_networkAccessManager = std::make_unique<QNetworkAccessManager>( this );
}

NetworkHandler::~NetworkHandler()
{
    m_networkAccessManager->deleteLater();
}


void NetworkHandler::downloadData()
{
    performGET(m_endpoint);
}

QByteArray NetworkHandler::getData()
{
    return m_response;
}

void NetworkHandler::performGET(const QString &url)
{
    QNetworkRequest request((QUrl(url)));
    request.setHeader( QNetworkRequest::ContentTypeHeader, QString( "application/json"));
    m_networkReply = std::shared_ptr<QNetworkReply>(m_networkAccessManager->get(request));
    connect(m_networkReply.get(), &QNetworkReply::finished, this, &NetworkHandler::networkReplyReadyRead);
}

void NetworkHandler::networkReplyReadyRead()
{
    if(m_networkReply->error() != QNetworkReply::NoError){
        return;
    }

    m_response = m_networkReply->readAll();
    m_networkReply->deleteLater();

    emit finished();
}

