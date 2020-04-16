#ifndef CONFERENCELISTDETAIL_H
#define CONFERENCELISTDETAIL_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QJsonValue>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include "../../models/conferencetablemodel.h"

#include "dataconference/dataformat.h"
#include "dataconference/dataxmlformat.h"
#include "dataconference/datajsonformat.h"
#include "dataconference/factoryformat.h"

#include "detailview/detailview.h"
#include "detailview/tuebix/tuebixdetailview.h"

class ConferenceListDetail : public QWidget
{
    Q_OBJECT
public:
    explicit ConferenceListDetail(QWidget *parent = nullptr);

    void conferenceData(QJsonObject headerConference, QJsonArray conferenceList);

    void setConferenceInfo(QJsonValue conferenceInfo);

signals:
    void backToMainPageClicked();

public slots:
    void setDetailViewInfo(const QModelIndex& index);

    void leaveThisPage();

private:
    QTableView* conferenceTableView;
    QHBoxLayout* mainLayout;
    ConferenceTableModel* conferenceModel;

    DataFormat* dataFromConference;
    DetailView* detailView;

    QList<QJsonValue> conferenceJsonData;

    QPushButton* backToFirstPageButton;

};

#endif // CONFERENCELISTDETAIL_H
