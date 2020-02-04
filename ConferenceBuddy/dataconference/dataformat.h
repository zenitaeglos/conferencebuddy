#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QObject>

class DataFormat : public QObject
{
    Q_OBJECT
public:
    explicit DataFormat(QObject *parent = nullptr);

    virtual QString format() = 0;

signals:

};

#endif // DATAFORMAT_H
