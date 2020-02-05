#include "dataformat.h"

DataFormat::DataFormat(QObject *parent) : QObject(parent),
    manager(new QNetworkAccessManager)
{

    // connections
    connect(manager, &QNetworkAccessManager::finished, this, &DataFormat::networkDataObtained);

}

void DataFormat::fetch()
{
    manager->get(QNetworkRequest(QUrl("https://www.tuebix.org/2019/giggity.xml")));
}
