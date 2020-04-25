#ifndef FOSDEMVIEW_H
#define FOSDEMVIEW_H

#include <QObject>
#include <QWidget>
#include <QJsonValue>
#include <QJsonObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>

class FosdemView : public QWidget
{
    Q_OBJECT
public:
    explicit FosdemView(QWidget *parent = nullptr);
    explicit FosdemView(QJsonValue talkInformation, QWidget *parent = nullptr);

signals:


private:
    QVBoxLayout* mainLayout;
    QLabel* titleTalk;
    QMediaPlayer* player;
    QVideoWidget* videoWidget;
};

#endif // FOSDEMVIEW_H
