#include "fosdemdetailview.h"

FosdemDetailView::FosdemDetailView(QWidget *parent) : DetailView(parent),
    mainLayout(new QVBoxLayout),
    titleConference(new QLabel(this)),
    talkConference(new QLabel(this))

{

    mainLayout->addWidget(titleConference);
    mainLayout->addWidget(talkConference);
    setLayout(mainLayout);
}

QString FosdemDetailView::viewName()
{
    return "fosdem";
}

void FosdemDetailView::setJsonData(QJsonValue data)
{
    titleConference->setText(data["conferenceTitle"].toString());
    talkConference->setText(data["title"].toString());
}
