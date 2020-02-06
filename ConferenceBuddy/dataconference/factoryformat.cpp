#include "factoryformat.h"

FactoryFormat::FactoryFormat(QObject *parent) : QObject(parent)
{

}

DataFormat *FactoryFormat::makeFormat(QString formatType, QString urlPath, QString schema, QObject *parent)
{
    Q_UNUSED(schema);
    if (formatType == "xml") {
        return new DataXmlFormat(urlPath, parent);
    }
    else if (formatType == "json") {
        return new DataJsonFormat(urlPath, parent);
    }
    return new DataXmlFormat();
}
