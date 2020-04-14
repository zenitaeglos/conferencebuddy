#ifndef FOSDEMDETAILVIEW_H
#define FOSDEMDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>

#include <QTextEdit>

#include "../detailview.h"

class FosdemDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit FosdemDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

    virtual void setJsonData(QJsonValue data) override;

signals:

private:
    QVBoxLayout* mainLayout;
    QLabel* titleConference;
    QLabel* talkConference;

};

#endif // FOSDEMDETAILVIEW_H
