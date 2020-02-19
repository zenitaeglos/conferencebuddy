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
    void setDescription(QString descriptionTag);
    QString getDescription() const;
    void setAbstract(QString abstractTag);
    QString getAbstract() const;

    static QVector<QString> getAttributes();
    void setAttribute(QString attributeOfTag, QString value);
    QString getId() const;

    QString getDate() const;
    QString getIndex() const;

    static QVector<QString> getLinkAttributes();

    void setLink(QString href, QString value);
    QMap<QString, QString> getLinks() const;

    QVector<QString> getPersons() const;
    void setPerson(QString person);


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
    QString id;
    QString date;
    QString index;

    QMap<QString, QString> linksMap;
    QVector<QString> persons;

};

#endif // GIGGITYEVENTTAG_H
