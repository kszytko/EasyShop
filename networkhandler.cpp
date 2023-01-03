#include "networkhandler.h"


NetworkHandler::NetworkHandler(QString dataEndpoint_, QObject *parent)
    : QObject{parent}, dataEndpoint(dataEndpoint_)
{
    m_networkAccessManager = std::make_unique<QNetworkAccessManager>( this );
}

NetworkHandler::~NetworkHandler()
{
    m_networkAccessManager->deleteLater();
}


void NetworkHandler::downloadData()
{
    performGET(dataEndpoint);
}

QJsonDocument NetworkHandler::getParsedJson()
{
    return m_parsedReply;
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

    QByteArray response = m_networkReply->readAll();
    m_networkReply->deleteLater();

    parseResponse(response);

}
void NetworkHandler::parseResponse(const QByteArray &response)
{
    m_parsedReply = QJsonDocument::fromJson(response);

    emit dataParsed();
}

