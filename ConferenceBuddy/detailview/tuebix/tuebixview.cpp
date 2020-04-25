#include "tuebixview.h"

TuebixView::TuebixView(QWidget *parent) : QWidget(parent)
{

}

TuebixView::TuebixView(QJsonValue talkInformation, QWidget *parent) : QWidget(parent),
    mainLayout(new QVBoxLayout),
    titleLabel(new QLabel(talkInformation["title"].toString(), this))
{
    mainLayout->addWidget(titleLabel);

    setLayout(mainLayout);
}
