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
