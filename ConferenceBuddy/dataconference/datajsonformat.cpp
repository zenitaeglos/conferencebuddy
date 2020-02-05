#include "datajsonformat.h"

DataJsonFormat::DataJsonFormat(QObject *parent) : DataFormat(parent)
{

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
