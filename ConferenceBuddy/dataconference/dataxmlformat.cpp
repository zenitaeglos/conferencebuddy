#include "dataxmlformat.h"

DataXmlFormat::DataXmlFormat()
{
    qDebug() << "calling xml";
}

QString DataXmlFormat::format()
{
    return "xml";
}

void DataXmlFormat::networkDataObtained(QNetworkReply *networkRelpy)
{
    qInfo() << "network info obtained";
    QByteArray xmlArray = networkRelpy->readAll();
    qDebug() << xmlArray;
}
