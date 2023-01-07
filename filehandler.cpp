#include "filehandler.h"
#include <QFile>
#include <QDebug>

FileHandler::FileHandler(QString fileName, QObject *parent)
    : DataHandler{parent}, m_fileName(fileName)
{
    qDebug() << "Loading " << fileName;
}

FileHandler::~FileHandler()
{

}

QByteArray FileHandler::getResult()
{
    qDebug() << "Data";
    return m_data;
}


void FileHandler::getProducts()
{
    qDebug() << "Reading file";


    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        m_data += file.readLine();
    }

    qDebug() << "Reading finished";

    emit finishedGET();
}

void FileHandler::postOrder(int totalPrice)
{
    int value = totalPrice * 1.23;
    m_data = QString::number(value).toUtf8();

    emit finishedPOST();
}
