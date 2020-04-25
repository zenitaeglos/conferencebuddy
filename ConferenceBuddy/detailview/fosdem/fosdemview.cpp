#include "fosdemview.h"

FosdemView::FosdemView(QWidget *parent) : QWidget(parent)
{

}

FosdemView::FosdemView(QJsonValue talkInformation, QWidget *parent) : QWidget(parent),
    mainLayout(new QVBoxLayout),
    titleTalk(new QLabel(talkInformation["title"].toString(), this)),
    player(new QMediaPlayer(this)),
    videoWidget(new QVideoWidget(this))
{
    QJsonObject links = talkInformation["links"].toObject();

    foreach(QString key, links.keys()) {
        if (links[key].toString().contains("mp4"))
            player->setMedia(QUrl(key));
    }



    player->setVideoOutput(videoWidget);
    player->play();

    mainLayout->addWidget(titleTalk);
    mainLayout->addWidget(videoWidget);

    setLayout(mainLayout);
}
