#ifndef DATAXMLFORMAT_H
#define DATAXMLFORMAT_H

#include <QObject>
#include <QDebug>
#include <QXmlStreamReader>
#include "dataformat.h"
#include "schema/schema.h"


class DataXmlFormat : public DataFormat
{
    Q_OBJECT
public:
    explicit DataXmlFormat(QObject *parent = nullptr);
    explicit DataXmlFormat(QString urlPath, QObject *parent = nullptr);

    virtual QString format() override;

signals:

public slots:
    void networkDataObtained(QNetworkReply *networkRelpy) override;

private:
    Schema* schema;

};

#endif // DATAXMLFORMAT_H
