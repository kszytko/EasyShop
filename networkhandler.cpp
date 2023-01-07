#include "networkhandler.h"


NetworkHandler::NetworkHandler(QString url, QString productEndpoint, QString orderEndpoint, QObject *parent)
    : DataHandler{parent}, m_url(url)
{
    m_networkAccessManager = std::make_unique<QNetworkAccessManager>( this );

    m_productsEndpoint.setScheme("http");
    m_productsEndpoint.setAuthority(m_url);
    m_productsEndpoint.setPath(productEndpoint);

    m_orderEndpoint.setScheme("http");
    m_orderEndpoint.setAuthority(m_url);
    m_orderEndpoint.setPath(orderEndpoint);


    connect(this, &NetworkHandler::urlChanged, this, &NetworkHandler::updateEndpoints);
}

NetworkHandler::~NetworkHandler()
{
    m_networkAccessManager->deleteLater();
}

void NetworkHandler::getProducts()
{
    performGET(m_productsEndpoint);
}

void NetworkHandler::postOrder(int totalPrice)
{
    QByteArray byteData = QString::number(totalPrice).toUtf8();
    performPOST(m_orderEndpoint, byteData);
}

QByteArray NetworkHandler::getResult()
{
    return m_response;
}

void NetworkHandler::performGET(const QUrl & url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader( QNetworkRequest::ContentTypeHeader, QString( "application/json"));

    m_networkReply = std::shared_ptr<QNetworkReply>(m_networkAccessManager->get(request));
    connect(m_networkReply.get(), &QNetworkReply::finished, this, &NetworkHandler::networkReplyReadyReadGET);

    qDebug() << "Perform get:" << url.toDisplayString();
}

void NetworkHandler::performPOST(const QUrl & url, const QByteArray & data)
{
    QNetworkRequest request(url);
    request.setHeader( QNetworkRequest::ContentTypeHeader, QString( "application/json"));

    m_networkReply = std::shared_ptr<QNetworkReply>(m_networkAccessManager->post(request, data));
    connect(m_networkReply.get(), &QNetworkReply::finished, this, &NetworkHandler::networkReplyReadyReadPOST);
}

void NetworkHandler::networkReplyReadyReadGET()
{
    qDebug() << "Read Get";
    networkReplyReadyRead();
    emit finishedGET();
}

void NetworkHandler::networkReplyReadyReadPOST()
{
    qDebug() << "Read Post";
    networkReplyReadyRead();
    emit finishedPOST();
}

void NetworkHandler::networkReplyReadyRead()
{
    if(m_networkReply->error() != QNetworkReply::NoError){
        return;
    }

    m_response = m_networkReply->readAll();
    m_networkReply->deleteLater();
}

void NetworkHandler::updateEndpoints()
{
    m_productsEndpoint.setAuthority(m_url);
    m_orderEndpoint.setAuthority(m_url);
}

QString NetworkHandler::url() const
{
    return m_url;
}

void NetworkHandler::setUrl(const QString &newUrl)
{
    if (m_url == newUrl)
        return;
    m_url = newUrl;
    emit urlChanged();
}
