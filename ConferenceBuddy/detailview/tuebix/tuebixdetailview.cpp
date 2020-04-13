#include "tuebixdetailview.h"

TuebixDetailView::TuebixDetailView(QWidget *parent) : DetailView(parent),
    //horizontalLayout(new QHBoxLayout(this)),
    conferenceTitle(new QLabel(this)),
    talkTitle(new QLabel(this)),
    mainLayout(new QVBoxLayout)
{
    mainLayout->addWidget(conferenceTitle);
    //mainLayout->addWidget(talkTitle);
    //horizontalLayout->addWidget(conferenceTitle);
    //horizontalLayout->addWidget(talkTitle);
    setLayout(mainLayout);
}

QString TuebixDetailView::viewName()
{
    return "tuebix";
}

void TuebixDetailView::setJsonData(QJsonValue data)
{
    conferenceTitle->setText(data["conferenceTitle"].toString());
    talkTitle->setText(data["title"].toString());
}
