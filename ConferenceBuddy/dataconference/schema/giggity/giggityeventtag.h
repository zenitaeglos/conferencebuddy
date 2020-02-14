#ifndef GIGGITYEVENTTAG_H
#define GIGGITYEVENTTAG_H

#include <QObject>
#include <QDebug>

class GiggityEventTag : public QObject
{
    Q_OBJECT
public:
    explicit GiggityEventTag(QObject *parent = nullptr);
    void setTitle(QString titleTag);
    QString getTitle() const;
    void setRoom(QString roomTag);
    QString getRoom() const;
    void setStart(QString startTag);
    QString getStart() const;
    void setDuration(QString durationTag);
    QString getDuration() const;
    void setSlug(QString slugTag);
    QString getSlug() const;

signals:

private:
    QString title;
    QString start;
    QString duration;
    QString room;
    QString slug;
    QString track;
    QString type;
    QString abstract;
    QString description;

};

#endif // GIGGITYEVENTTAG_H
