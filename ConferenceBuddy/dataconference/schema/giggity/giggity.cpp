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
}

void Giggity::setSubTag(QString key)
{
    if (key == "conference")
        subTag = Conference;
    else if (key == "day")
        subTag = Day;
    else if (key == "room")
        subTag = Room;
    else if (key == "event")
        subTag = Event;
}

void Giggity::unsetSubTag(QString key)
{
    if (key == "conference")
        subTag = NoSub;
    else if (key == "tag")
        subTag = NoSub;
}

QJsonObject Giggity::conferenceHeader()
{
    QJsonObject confHeader;
    confHeader.insert("title", this->title);
    confHeader.insert("city", this->city);
    confHeader.insert("start", this->start);
    confHeader.insert("end", this->end);
    return confHeader;
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
}
