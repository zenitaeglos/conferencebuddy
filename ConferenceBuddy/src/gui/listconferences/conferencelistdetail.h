#ifndef CONFERENCELISTDETAIL_H
#define CONFERENCELISTDETAIL_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include "../../models/conferencetablemodel.h"

class ConferenceListDetail : public QWidget
{
    Q_OBJECT
public:
    explicit ConferenceListDetail(QWidget *parent = nullptr);

signals:

private:
    QTableView* conferenceTableView;
    QHBoxLayout* mainLayout;
    ConferenceTableModel* conferenceModel;

};

#endif // CONFERENCELISTDETAIL_H
