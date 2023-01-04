#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QString fileName, QObject *parent = nullptr);
    ~FileHandler();

    void downloadData();
    QByteArray getData();

signals:
    void finished();

private:
    QString m_fileName;
    QByteArray m_data;
};
#endif // FILEHANDLER_H
