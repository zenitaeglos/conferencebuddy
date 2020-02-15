#include "giggity.h"

Giggity::Giggity(QObject *parent) : Schema(parent),
    subTag(NoSub)
{

}

QString Giggity::getTitle()
{
    return this->title;
}

void Giggity::setValue(QString key, QString value)
{
    if (subTag == Conference)
        setValueConferenceTag(key, value);
    else if (subTag == Event)
        setValueEventTag(key, value);
}

void Giggity::setSubTag(QString key)
{
    if (key == "conference")
        subTag = Conference;
    else if (key == "day") {
        subTag = Day;
        this->attributes = getDayAttributes();
    }
    else if (key == "room") {
        attributes.clear();
        if (subTag == Day)
            subTag = Room;
    }
    else if (key == "event") {
        if (eventTag.size() > 0) {
            GiggityEventTag* lastEventTag = eventTag.last();
            lastEventTag->setAttribute("date", dateAttribute);
            lastEventTag->setAttribute("index", indexAttribute);
        }
        attributes.clear();
        attributes = GiggityEventTag::getAttributes();
        subTag = Event;
        GiggityEventTag* eventTagElement = new GiggityEventTag(this);
        eventTag.push_back(eventTagElement);
    }
    else {
        attributes.clear();
    }
}

void Giggity::unsetSubTag(QString key)
{
    if (key == "conference")
        subTag = NoSub;
    else if (key == "tag")
        subTag = NoSub;
    else if (key == "room") {
        if (subTag == Event)
            return;
        subTag = Day;
    }
    else if (key == "persons")
        subTag = Event;
    else if (key == "links")
        subTag = Event;
    else if (key == "event")
        subTag = Room;


    if (eventTag.size() == 76) {
        foreach(GiggityEventTag* eventTagElement, eventTag) {
            qDebug() << eventTagElement->getTitle() << eventTagElement << eventTagElement->getRoom() << eventTagElement->getSlug()
                     << eventTagElement->getDuration() << eventTagElement->getId() << eventTagElement->getIndex() << eventTagElement->getDate();
        }
    }

}

QJsonObject Giggity::conferenceHeader()
{
    QJsonObject confHeader;
    confHeader.insert("title", this->title);
    confHeader.insert("city", this->city);
    confHeader.insert("start", this->start);
    confHeader.insert("end", this->end);
    confHeader.insert("days", this->days);
    return confHeader;
}

QJsonArray Giggity::conferenceList()
{
    return QJsonArray();
}

QVector<QString> Giggity::attributeValues()
{
    return attributes;
}

void Giggity::setAttributeOfTag(QString attributeOfTag, QString value)
{
    if (subTag == Day) {
        if (attributeOfTag == "date")
            dateAttribute = value;
        else if (attributeOfTag == "index")
            indexAttribute = value;
    }
    else if (subTag == Event) {
        GiggityEventTag* eventTagElement = eventTag.last();
        eventTagElement->setAttribute(attributeOfTag, value);
        eventTagElement->setAttribute("date", dateAttribute);
        eventTagElement->setAttribute("index", indexAttribute);
    }
}

QVector<QString> Giggity::getDayAttributes() const
{
    QVector<QString> dayAttributes;
    dayAttributes.push_back("date");
    dayAttributes.push_back("index");
    return dayAttributes;
}

void Giggity::setValueConferenceTag(QString key, QString value)
{
    if (key == "title")
        title = value;
    else if (key == "city")
        city = value;
    else if (key == "start")
        start = value;
    else if (key == "end")
        end = value;
    else if (key == "days")
        days = value;
}

void Giggity::setValueEventTag(QString key, QString value)
{
    GiggityEventTag* eventTagElement = eventTag.last();
    if (key == "title")
        eventTagElement->setTitle(value);
    else if (key == "room")
        eventTagElement->setRoom(value);
    else if (key == "start")
        eventTagElement->setStart(value);
    else if (key == "slug")
        eventTagElement->setSlug(value);
    else if (key == "duration")
        eventTagElement->setDuration(value);
    else if (key == "description")
        eventTagElement->setDescription(value);
    else if (key == "abstract")
        eventTagElement->setAbstract(value);
}
