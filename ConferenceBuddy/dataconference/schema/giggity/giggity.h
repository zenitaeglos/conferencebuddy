#ifndef GIGGITY_H
#define GIGGITY_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "schema/schema.h"

class Giggity : public Schema
{
    Q_OBJECT
public:
    enum SubTag {
        NoSub,
        Conference,
        Day,
        Room,
        Event,
        Persons,
        Links
    };
    explicit Giggity(QObject *parent = nullptr);

    QString getTitle();
    virtual void setValue(QString key, QString value) override;
    virtual void setSubTag(QString key) override;
    virtual void unsetSubTag(QString key) override;
    virtual QJsonObject conferenceHeader() override;

signals:


private:
    void setValueConferenceTag(QString key, QString value);
    SubTag subTag;
    QString title;
    QString city;
    QString start;
    QString end;

};

#endif // GIGGITY_H
