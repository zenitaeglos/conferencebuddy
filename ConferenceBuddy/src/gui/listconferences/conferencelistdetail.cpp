#include "conferencelistdetail.h"

ConferenceListDetail::ConferenceListDetail(QWidget *parent) : QWidget(parent),
    conferenceTableView(new QTableView(this)),
    mainLayout(new QHBoxLayout),
    conferenceModel(new ConferenceTableModel(this)),
    //dataFromConference(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", this))
    dataFromConference(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this))
{
    conferenceModel->setTalkListData(QList<QString>());

    conferenceTableView->setModel(conferenceModel);

    mainLayout->addWidget(conferenceTableView);
    setLayout(mainLayout);

    dataFromConference->fetch();

    // connections
    connect(dataFromConference, &DataFormat::conferenceChanged, this, &ConferenceListDetail::conferenceData);
}

void ConferenceListDetail::conferenceData(QJsonObject headerConference, QJsonArray conferenceList)
{
    Q_UNUSED(headerConference);
    QList<QString> data;

    for (int i = 0; i < conferenceList.size(); i++) {
        data.append(conferenceList.at(i)["title"].toString());
    }
    conferenceModel->setTalkListData(data);
}
