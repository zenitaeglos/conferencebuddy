#include "fosdemdetailview.h"

FosdemDetailView::FosdemDetailView(QWidget *parent) : DetailView(parent),
    horizontalLayout(new QHBoxLayout(this)),
    sliderExampleToDelete(new QSlider(this))
{
    sliderExampleToDelete->setOrientation(Qt::Horizontal);
    horizontalLayout->addWidget(sliderExampleToDelete);

    setLayout(horizontalLayout);
}

QString FosdemDetailView::viewName()
{
    return "fosdem";
}

void FosdemDetailView::setJsonData(QJsonValue data)
{

}
