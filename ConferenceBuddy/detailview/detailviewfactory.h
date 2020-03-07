#ifndef DETAILVIEWFACTORY_H
#define DETAILVIEWFACTORY_H

#include <QObject>

class DetailViewFactory : public QObject
{
    Q_OBJECT
public:
    explicit DetailViewFactory(QObject *parent = nullptr);

signals:

};

#endif // DETAILVIEWFACTORY_H
