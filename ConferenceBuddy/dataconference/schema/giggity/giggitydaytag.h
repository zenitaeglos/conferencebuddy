#ifndef GIGGITYDAYTAG_H
#define GIGGITYDAYTAG_H

#include <QObject>
#include <QVector>
#include <QtCore/QDebug>
#include "giggityroomtag.h"

class GiggityDayTag : public QObject
{
    Q_OBJECT
public:
    explicit GiggityDayTag(QObject *parent = nullptr);
    static QVector<QString> getAttributes();
    void setAttribute(QString attribute, QString value);
    QString getIndex() const;
    QString getDate() const;

signals:

private:
    QString indexAttribute;
    QString dateAttribute;
    QVector<GiggityRoomTag*> roomTag;
};

#endif // GIGGITYDAYTAG_H
