#include "dataxmlformat.h"
#include "schema/giggity/giggity.h"


DataXmlFormat::DataXmlFormat(QObject *parent) : DataFormat(parent)
{

}

DataXmlFormat::DataXmlFormat(QString urlPath, QObject *parent) : DataFormat(parent),
    schema(new Giggity(this))
{
    this->urlPath = urlPath;
}

DataXmlFormat::DataXmlFormat(QString urlPath, Schema *schema, QObject *parent) : DataFormat(parent),
    schema(schema)
{
    this->urlPath = urlPath;
}

QString DataXmlFormat::format()
{
    return "xml";
}

QJsonObject DataXmlFormat::headerInformationConference()
{
    return schema->conferenceHeader();
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
                schema->setAttributeOfTag(attribute, xmlReader.attributes().value(attribute).toString());
            }
            schema->setSettable(xmlReader.name().toString());
            if (schema->settable()) {
                const QString key = xmlReader.name().toString();

                //if (key == "person")
                //    qDebug() << key << "ya he conseguido que person pase la prueba";
                xmlReader.readNext();
                schema->setValue(key, xmlReader.text().toString());
            }
        }
        if (token == QXmlStreamReader::EndElement) {
            schema->unsetSubTag(xmlReader.name().toString());
        }
    }

    emit headerChanged(schema->conferenceHeader());
}

void DataXmlFormat::test(QJsonObject headerObject)
{
    //emit headerChanged(headerObject);
    qDebug() << "header object" << headerObject;
}
