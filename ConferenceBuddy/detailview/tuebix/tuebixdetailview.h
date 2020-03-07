#ifndef TUEBIXDETAILVIEW_H
#define TUEBIXDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include "detailview.h"

class TuebixDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit TuebixDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

signals:

};

#endif // TUEBIXDETAILVIEW_H
