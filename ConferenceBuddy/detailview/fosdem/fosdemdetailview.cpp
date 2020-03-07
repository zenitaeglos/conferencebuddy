#include "fosdemdetailview.h"

FosdemDetailView::FosdemDetailView(QWidget *parent) : DetailView(parent),
    horizontalLayout(new QHBoxLayout(this)),
    sliderExampleToDelete(new QSlider(this))
{
    horizontalLayout->addWidget(sliderExampleToDelete);

    setLayout(horizontalLayout);
}

QString FosdemDetailView::viewName()
{
    return "fosdem";
}
