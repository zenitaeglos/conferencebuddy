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
