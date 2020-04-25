#ifndef MAINDETAILVIEW_H
#define MAINDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>
#include <QJsonValue>
#include <QVBoxLayout>
#include <QDebug>

#include "tuebix/tuebixview.h"
#include "fosdem/fosdemview.h"

class MainDetailView : public QWidget
{
    Q_OBJECT
public:
    explicit MainDetailView(QWidget *parent = nullptr);

    void setDetailInfo(QJsonValue info);

signals:


private:
    QVBoxLayout* mainLayout;
    QWidget* tuebixView;
    FosdemView* fosdemView;

};

#endif // MAINDETAILVIEW_H
