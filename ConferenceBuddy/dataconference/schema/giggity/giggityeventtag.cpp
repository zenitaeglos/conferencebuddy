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
