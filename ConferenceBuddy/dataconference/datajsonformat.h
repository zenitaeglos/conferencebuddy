#ifndef DATAJSONFORMAT_H
#define DATAJSONFORMAT_H

#include <QObject>
#include "dataformat.h"

class DataJsonFormat : public DataFormat
{
    Q_OBJECT
public:
    explicit DataJsonFormat();
    virtual QString format() override;


signals:

};

#endif // DATAJSONFORMAT_H
