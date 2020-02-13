#ifndef GIGGITYDAYTAG_H
#define GIGGITYDAYTAG_H

#include <QObject>
#include <QVector>
#include "giggityroomtag.h"

class GiggityDayTag : public QObject
{
    Q_OBJECT
public:
    explicit GiggityDayTag(QObject *parent = nullptr);

signals:

private:
    QString indexAttribute;
    QString dateAttribute;
    QVector<GiggityRoomTag*> roomTag;
};

#endif // GIGGITYDAYTAG_H
