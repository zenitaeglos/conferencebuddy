#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class DataFormat : public QObject
{
    Q_OBJECT
public:
    explicit DataFormat(QObject *parent = nullptr);

    virtual QString format() = 0;

    void fetch();

signals:

public slots:
    virtual void networkDataObtained(QNetworkReply* networkRelpy) = 0;


private:
    QNetworkAccessManager* manager;

};

#endif // DATAFORMAT_H
