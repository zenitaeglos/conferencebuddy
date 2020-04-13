#ifndef CONFERENCELISTDETAIL_H
#define CONFERENCELISTDETAIL_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include "../../models/conferencetablemodel.h"

#include "dataconference/dataformat.h"
#include "dataconference/dataxmlformat.h"
#include "dataconference/datajsonformat.h"
#include "dataconference/factoryformat.h"

class ConferenceListDetail : public QWidget
{
    Q_OBJECT
public:
    explicit ConferenceListDetail(QWidget *parent = nullptr);

    void conferenceData(QJsonObject headerConference, QJsonArray conferenceList);

signals:

private:
    QTableView* conferenceTableView;
    QHBoxLayout* mainLayout;
    ConferenceTableModel* conferenceModel;

    DataFormat* dataFromConference;

};

#endif // CONFERENCELISTDETAIL_H
