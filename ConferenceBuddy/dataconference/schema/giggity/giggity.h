#ifndef GIGGITY_H
#define GIGGITY_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <QDebug>
#include "schema/schema.h"
#include "giggityeventtag.h"


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
    virtual QJsonArray conferenceList() override;
    virtual QVector<QString> attributeValues() override;
    virtual void setAttributeOfTag(QString attributeOfTag, QString value) override;


signals:


private:
    QVector<QString> getDayAttributes() const;
    void setValueConferenceTag(QString key, QString value);
    void setValueEventTag(QString key, QString value);
    SubTag subTag;
    QString title;
    QString city;
    QString start;
    QString end;
    QString days;
    QVector<QString> attributes;
    QVector<GiggityEventTag*> eventTag;
    QString dateAttribute;
    QString indexAttribute;

};

#endif // GIGGITY_H
