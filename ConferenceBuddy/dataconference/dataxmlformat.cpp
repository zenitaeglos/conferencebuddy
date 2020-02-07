#include "dataxmlformat.h"

DataXmlFormat::DataXmlFormat(QObject *parent) : DataFormat(parent)
{
    qDebug() << "calling xml";
}

DataXmlFormat::DataXmlFormat(QString urlPath, QObject *parent) : DataFormat(parent)
{
    this->urlPath = urlPath;
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
    QXmlStreamReader xmlReader(xmlArray);

    while (!xmlReader.atEnd()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") {
                xmlReader.readNext();
                qDebug() << "title" << xmlReader.text();
            }
            if (xmlReader.name() == "room") {
                xmlReader.readNext();
                qDebug() << "room" << xmlReader.text();
            }
            if (xmlReader.name() == "link") {
                qDebug() << xmlReader.attributes().value("href");
                xmlReader.readNext();


                qDebug() << "link" << xmlReader.text() << xmlReader.attributes().value("href");
            }
        }
    }
}
