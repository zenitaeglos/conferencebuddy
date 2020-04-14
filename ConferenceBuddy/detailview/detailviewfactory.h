#ifndef DETAILVIEWFACTORY_H
#define DETAILVIEWFACTORY_H

#include <QObject>
#include "detailview.h"

class DetailViewFactory : public QObject
{
    Q_OBJECT
public:
    explicit DetailViewFactory(QObject *parent = nullptr);

    static DetailView* makeDetailView(QString name);

signals:

};

#endif // DETAILVIEWFACTORY_H
