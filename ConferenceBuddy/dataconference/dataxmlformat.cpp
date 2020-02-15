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
    QByteArray xmlArray = networkRelpy->readAll();
    QXmlStreamReader xmlReader(xmlArray);

    while (!xmlReader.atEnd()) {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement) {
            schema->setSubTag(xmlReader.name().toString());
            QVector<QString> attributesTag = schema->attributeValues();
            foreach(QString attribute, attributesTag) {
                //Give the attribute
                qDebug() << "dataxmlformat sends" << attribute << xmlReader.attributes().value(attribute).toString();
                schema->setAttributeOfTag(attribute, xmlReader.attributes().value(attribute).toString());
            }
            const QString key = xmlReader.name().toString();
            xmlReader.readNext();
            schema->setValue(key, xmlReader.text().toString());
        }
        if (token == QXmlStreamReader::EndElement) {
            schema->unsetSubTag(xmlReader.name().toString());
        }
    }
    Giggity* gig = static_cast<Giggity*>(schema);
    qDebug() << gig->conferenceHeader();
}
