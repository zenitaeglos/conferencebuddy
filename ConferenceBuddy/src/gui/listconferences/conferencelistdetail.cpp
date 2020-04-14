#include "conferencelistdetail.h"

ConferenceListDetail::ConferenceListDetail(QWidget *parent) : QWidget(parent),
    conferenceTableView(new QTableView(this)),
    mainLayout(new QHBoxLayout),
    conferenceModel(new ConferenceTableModel(this)),
    //dataFromConference(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", this))
    dataFromConference(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this)),
    detailView(new TuebixDetailView(this))
{
    conferenceModel->setTalkListData(QList<QString>());

    conferenceTableView->setModel(conferenceModel);

    mainLayout->addWidget(conferenceTableView);
    mainLayout->addWidget(detailView);
    setLayout(mainLayout);

    dataFromConference->fetch();

    // connections
    connect(dataFromConference, &DataFormat::conferenceChanged, this, &ConferenceListDetail::conferenceData);

    connect(conferenceTableView, &QTableView::doubleClicked, this, &ConferenceListDetail::setDetailViewInfo);
}

void ConferenceListDetail::conferenceData(QJsonObject headerConference, QJsonArray conferenceList)
{
    Q_UNUSED(headerConference);
    QList<QString> data;
    QList<QJsonValue> dataJson;
    detailView->setJsonData(conferenceList.at(0));
    for (int i = 0; i < conferenceList.size(); i++) {
        data.append(conferenceList.at(i)["title"].toString());
        dataJson.append(conferenceList.at(i));
        conferenceJsonData.append(conferenceList.at(i));
    }
    //conferenceModel->setTalkListData(data);
    conferenceModel->setJsonTalkListData(dataJson);
}

void ConferenceListDetail::setDetailViewInfo(const QModelIndex &index)
{
    detailView->setJsonData(conferenceJsonData.at(index.row()));
}
