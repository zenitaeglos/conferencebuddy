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
    else if (subTag == Event) {
        if (key == "title")
            qDebug() << key << "key to send with this laue" << value;
        setValueEventTag(key, value);

    }
}

void Giggity::setSubTag(QString key)
{
    if (key == "conference")
        subTag = Conference;
    else if (key == "day") {
        subTag = Day;
        this->attributes = GiggityDayTag::getAttributes();
    }
    else if (key == "room") {
        if (subTag == Day)
            subTag = Room;
    }
    else if (key == "event") {
        qDebug() << "subtag event selected";
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
    qDebug() << eventTag.size() << "how many events";
    if (eventTag.size() == 76) {
        foreach(GiggityEventTag* eventTagElement, eventTag) {
            qDebug() << eventTagElement->getTitle() << eventTagElement << eventTagElement->getRoom();
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

void Giggity::setValueConferenceTag(QString key, QString value)
{
    qDebug() << "key" << key << value;
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
    qDebug() << "tu the mun an billon" << key << value;
    GiggityEventTag* eventTagElement = eventTag.last();
    if (key == "title") {
        qDebug() << "and more beyond";
        eventTagElement->setTitle(value);
    }
    if (key == "room") {
        eventTagElement->setRoom(value);
    }
}
