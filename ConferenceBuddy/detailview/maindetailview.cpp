#include "maindetailview.h"

MainDetailView::MainDetailView(QWidget *parent) : QWidget(parent),
    mainLayout(new QVBoxLayout),
    tuebixView(nullptr),
    fosdemView(nullptr)
{
    setLayout(mainLayout);
}

void MainDetailView::setDetailInfo(QJsonValue info)
{

    if (mainLayout->layout()->takeAt(0) != NULL) {
        //QWidget* widgetToDelete = qobject_cast<QWidget*>(mainLayout->layout()->takeAt(0)->widget());
        mainLayout->removeWidget(tuebixView);
        delete tuebixView;
    }
    qDebug() << info;
    //delete tuebixView;

    if (info["conferenceTitle"].toString().contains("Tübix")) {
        tuebixView = new TuebixView(info);
        mainLayout->addWidget(tuebixView);
    }
    else if (info["conferenceTitle"].toString().contains("FOSDEM")) {
        tuebixView = new FosdemView(info);
        mainLayout->addWidget(tuebixView);
    }
}
