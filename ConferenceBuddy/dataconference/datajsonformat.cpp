#include "datajsonformat.h"

DataJsonFormat::DataJsonFormat(QObject *parent) : DataFormat(parent)
{

}

DataJsonFormat::DataJsonFormat(QString urlPath, QObject *parent) : DataFormat(parent)
{
    this->urlPath = urlPath;
    qInfo() << this->urlPath;
}

QString DataJsonFormat::format()
{
    return "json";
}

void DataJsonFormat::networkDataObtained(QNetworkReply *networkRelpy)
{
    qInfo() << "network reply";
    QByteArray jsonArray = networkRelpy->readAll();
    qDebug() << jsonArray;
}
