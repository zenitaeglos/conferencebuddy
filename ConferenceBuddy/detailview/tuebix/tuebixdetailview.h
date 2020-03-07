#ifndef TUEBIXDETAILVIEW_H
#define TUEBIXDETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "../detailview.h"

class TuebixDetailView : public DetailView
{
    Q_OBJECT
public:
    explicit TuebixDetailView(QWidget *parent = nullptr);

    virtual QString viewName() override;

signals:


private:
    QPushButton* buttonExample;
    QHBoxLayout* horizontalLayout;

};

#endif // TUEBIXDETAILVIEW_H
