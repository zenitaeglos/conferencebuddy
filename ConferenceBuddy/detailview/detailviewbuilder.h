#ifndef DETAILVIEWBUILDER_H
#define DETAILVIEWBUILDER_H

#include <QObject>

class DetailViewBuilder : public QObject
{
    Q_OBJECT
public:
    explicit DetailViewBuilder(QObject *parent = nullptr);

signals:

};

#endif // DETAILVIEWBUILDER_H
