#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include "datahandler.h"

class FileHandler : public DataHandler
{
    Q_OBJECT
public:
    explicit FileHandler(QString fileName, QObject *parent = nullptr);
    ~FileHandler();

    void downloadData() override;
    QByteArray getData() override;

private:
    QString m_fileName;
    QByteArray m_data;
};
#endif // FILEHANDLER_H
