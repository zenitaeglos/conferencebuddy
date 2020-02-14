#ifndef SCHEMA_H
#define SCHEMA_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QtCore/QVector>

class Schema : public QObject
{
    Q_OBJECT
public:
    explicit Schema(QObject *parent = nullptr);

    virtual void setValue(QString key, QString value) = 0;
    virtual void setSubTag(QString key) = 0;
    virtual void unsetSubTag(QString key) = 0;
    virtual QJsonObject conferenceHeader() = 0;
    virtual QJsonArray conferenceList() = 0;
    virtual QVector<QString> attributeValues() = 0;
    virtual void setAttributeOfTag(QString attributeOfTag, QString value) = 0;

signals:

};

#endif // SCHEMA_H
