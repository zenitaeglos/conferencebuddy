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
    explicit DataXmlFormat(QString urlPath, Schema* schema, QObject *parent = nullptr);

    virtual QString format() override;

    virtual QJsonObject headerInformationConference() override;

signals:


public slots:
    void networkDataObtained(QNetworkReply *networkRelpy) override;

    void test(QJsonObject headerObject);

private:
    Schema* schema;

};

#endif // DATAXMLFORMAT_H
