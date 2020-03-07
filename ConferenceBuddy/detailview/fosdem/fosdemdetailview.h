#ifndef FOSDEMDETAILVIEW_H
#define FOSDEMDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include "../detailview.h"

class FosdemDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit FosdemDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

signals:

private:
    QHBoxLayout* horizontalLayout;
    QSlider* sliderExampleToDelete;

};

#endif // FOSDEMDETAILVIEW_H
