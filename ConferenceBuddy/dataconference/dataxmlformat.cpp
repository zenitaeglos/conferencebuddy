#include "dataxmlformat.h"
#include "schema/giggity/giggity.h"

DataXmlFormat::DataXmlFormat(QObject *parent) : DataFormat(parent)
{
    qDebug() << "calling xml";
}

DataXmlFormat::DataXmlFormat(QString urlPath, QObject *parent) : DataFormat(parent),
    schema(new Giggity(this))
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
    //qDebug() << xmlArray;
    QXmlStreamReader xmlReader(xmlArray);

    while (!xmlReader.atEnd()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement) {
            schema->setSubTag(xmlReader.name().toString());
            const QString key = xmlReader.name().toString();
            qDebug() << key;
            xmlReader.readNext();
            qDebug() << xmlReader.text().toString();
            schema->setValue(key, xmlReader.text().toString());
            /*
            schema->setValue(xmlReader.name().toString(), "name");
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
            */
        }
        if (token == QXmlStreamReader::EndElement) {
            //qDebug() << "end element";
        }
    }
    Giggity* gig = static_cast<Giggity*>(schema);
    qDebug() << gig->conferenceHeader();
}
