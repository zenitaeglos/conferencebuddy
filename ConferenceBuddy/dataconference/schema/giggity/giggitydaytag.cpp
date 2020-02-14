#include "giggitydaytag.h"

GiggityDayTag::GiggityDayTag(QObject *parent) : QObject(parent),
    indexAttribute(""),
    dateAttribute("")
{

}

QVector<QString> GiggityDayTag::getAttributes()
{
    QVector<QString> attributes;
    attributes.push_back("date");
    attributes.push_back("index");
    return attributes;
}

void GiggityDayTag::setAttribute(QString attribute, QString value)
{
    qDebug() << "attributes" << attribute << value;
}

QString GiggityDayTag::getIndex() const
{
    return indexAttribute;
}

QString GiggityDayTag::getDate() const
{
    return dateAttribute;
}
