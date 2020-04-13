#ifndef TUEBIXDETAILVIEW_H
#define TUEBIXDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "../detailview.h"

class TuebixDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit TuebixDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

    virtual void setJsonData(QJsonValue data) override;

signals:


private:
    //QHBoxLayout* horizontalLayout;
    QLabel* conferenceTitle;
    QLabel* talkTitle;
    QVBoxLayout* mainLayout;

};

#endif // TUEBIXDETAILVIEW_H
