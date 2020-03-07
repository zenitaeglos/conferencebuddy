#ifndef FOSDEMDETAILVIEW_H
#define FOSDEMDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include "../detailview.h"

class FosdemDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit FosdemDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

signals:

};

#endif // FOSDEMDETAILVIEW_H
