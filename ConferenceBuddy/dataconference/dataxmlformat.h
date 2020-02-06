#ifndef DATAXMLFORMAT_H
#define DATAXMLFORMAT_H

#include <QObject>
#include <QDebug>
#include "dataformat.h"

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

};

#endif // DATAXMLFORMAT_H
