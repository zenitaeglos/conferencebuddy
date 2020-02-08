#include "dataformat.h"

DataFormat::DataFormat(QObject *parent) : QObject(parent),
    schemaXml(new ConverterToXmlSchema(this)),
    manager(new QNetworkAccessManager)
{
    //urlPath = "https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2";
    // connections
    connect(manager, &QNetworkAccessManager::finished, this, &DataFormat::networkDataObtained);
}

DataFormat::DataFormat(QString urlPath, QObject *parent) : QObject(parent),
    urlPath(urlPath)
{

    //connections
    connect(manager, &QNetworkAccessManager::finished, this, &DataFormat::networkDataObtained);
}

void DataFormat::fetch()
{
    //https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2
    //manager->get(QNetworkRequest(QUrl("https://www.tuebix.org/2019/giggity.xml")));
    manager->get(QNetworkRequest(QUrl(urlPath)));
}
