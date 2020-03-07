#include "tuebixdetailview.h"

TuebixDetailView::TuebixDetailView(QWidget *parent) : DetailView(parent),
    buttonExample(new QPushButton(this)),
    horizontalLayout(new QHBoxLayout(this))
{
    buttonExample->setText("Hola");
    horizontalLayout->addWidget(buttonExample);
    setLayout(horizontalLayout);
}

QString TuebixDetailView::viewName()
{
    return "tuebix";
}
