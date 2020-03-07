#ifndef DATAJSONFORMAT_H
#define DATAJSONFORMAT_H

#include <QObject>
#include <QtCore/QJsonObject>
#include "dataformat.h"

class DataJsonFormat : public DataFormat
{
    Q_OBJECT
public:
    explicit DataJsonFormat(QObject *parent = nullptr);
    explicit DataJsonFormat(QString urlPath, QObject *parent = nullptr);
    virtual QString format() override;


    virtual QJsonObject headerInformationConference() override;

public slots:
    virtual void networkDataObtained(QNetworkReply *networkRelpy) override;


signals:

};

#endif // DATAJSONFORMAT_H
