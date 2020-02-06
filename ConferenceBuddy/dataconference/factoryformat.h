#ifndef FACTORYFORMAT_H
#define FACTORYFORMAT_H

#include <QObject>
#include "datajsonformat.h"
#include "dataxmlformat.h"
#include "dataformat.h"

class FactoryFormat : public QObject
{
    Q_OBJECT
public:
    explicit FactoryFormat(QObject *parent = nullptr);

    virtual QString description() = 0;
    static DataFormat* makeFormat(QString formatType, QString urlPath, QString schema, QObject *parent = nullptr);

signals:

};

#endif // FACTORYFORMAT_H
