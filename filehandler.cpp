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

void FileHandler::downloadData()
{
    qDebug() << "Reading file";


    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        m_data += file.readLine();
    }

    qDebug() << "Reading finished";

    emit finished();
}

QByteArray FileHandler::getData()
{
    qDebug() << "Data";
    return m_data;
}
