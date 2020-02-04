#ifndef DATAXMLFORMAT_H
#define DATAXMLFORMAT_H

#include <QObject>
#include "dataformat.h"

class DataXmlFormat : public DataFormat
{
    Q_OBJECT
public:
    explicit DataXmlFormat();

    virtual QString format() override;

signals:

};

#endif // DATAXMLFORMAT_H
