#include "giggityeventtag.h"

GiggityEventTag::GiggityEventTag(QObject *parent) : QObject(parent)
{

}

void GiggityEventTag::setTitle(QString titleTag)
{
    title = titleTag;
}

QString GiggityEventTag::getTitle() const
{
    return title;
}

void GiggityEventTag::setRoom(QString roomTag)
{
    room = roomTag;
}

QString GiggityEventTag::getRoom() const
{
    return room;
}

void GiggityEventTag::setStart(QString startTag)
{
    start = startTag;
}

QString GiggityEventTag::getStart() const
{
    return start;
}

void GiggityEventTag::setDuration(QString durationTag)
{
    duration = durationTag;
}

QString GiggityEventTag::getDuration() const
{
    return duration;
}

void GiggityEventTag::setSlug(QString slugTag)
{
    slug = slugTag;
}

QString GiggityEventTag::getSlug() const
{
    return slug;
}

void GiggityEventTag::setDescription(QString descriptionTag)
{
    description = descriptionTag;
}

QString GiggityEventTag::getDescription() const
{
    return description;
}

void GiggityEventTag::setAbstract(QString abstractTag)
{
    abstract = abstractTag;
}

QString GiggityEventTag::getAbstract() const
{
    return abstract;
}

QVector<QString> GiggityEventTag::getAttributes()
{
    QVector<QString> attributes;
    attributes.push_back("id");
    return attributes;
}

void GiggityEventTag::setAttribute(QString attributeOfTag, QString value)
{
    qDebug() << attributeOfTag << value;
    if (attributeOfTag == "id")
        id = value;
    else if (attributeOfTag == "date")
        date = value;
    else if (attributeOfTag == "index")
        index = value;
}

QString GiggityEventTag::getId() const
{
    return id;
}

QString GiggityEventTag::getDate() const
{
    return date;
}

QString GiggityEventTag::getIndex() const
{
    return index;
}

QVector<QString> GiggityEventTag::getLinkAttributes()
{
    QVector<QString> attributes;
    attributes.push_back("href");
    return attributes;
}

void GiggityEventTag::setLink(QString href, QString value)
{
    linksMap[href] = value;
}

QMap<QString, QString> GiggityEventTag::getLinks() const
{
    return linksMap;
}

QVector<QString> GiggityEventTag::getPersons() const
{
    return persons;
}

void GiggityEventTag::setPerson(QString person)
{
    persons.push_back(person);
}

