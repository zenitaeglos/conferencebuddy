#ifndef CONVERTERTOXMLSCHEMA_H
#define CONVERTERTOXMLSCHEMA_H

#include <QObject>
#include <QXmlStreamWriter>


class ConverterToXmlSchema : public QObject
{
    Q_OBJECT
public:
    explicit ConverterToXmlSchema(QObject *parent = nullptr);

signals:

};

#endif // CONVERTERTOXMLSCHEMA_H
