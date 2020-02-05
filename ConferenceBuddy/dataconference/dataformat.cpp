#include "dataformat.h"

DataFormat::DataFormat(QObject *parent) : QObject(parent),
    manager(new QNetworkAccessManager)
{

    // connections
    connect(manager, &QNetworkAccessManager::finished, this, &DataFormat::networkDataObtained);
}

void DataFormat::fetch()
{
    //https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2
    //manager->get(QNetworkRequest(QUrl("https://www.tuebix.org/2019/giggity.xml")));
    manager->get(QNetworkRequest(QUrl("https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2")));
}
