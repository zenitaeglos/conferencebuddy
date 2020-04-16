#include "conferencelistdetail.h"

ConferenceListDetail::ConferenceListDetail(QWidget *parent) : QWidget(parent),
    conferenceTableView(new QTableView(this)),
    mainLayout(new QHBoxLayout),
    conferenceModel(new ConferenceTableModel(this)),
    dataFromConference(nullptr),
    //dataFromConference(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", this)),
    //dataFromConference(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this)),
    //detailView(new TuebixDetailView(this)),
    detailView(nullptr),
    backToFirstPageButton(new QPushButton("Back", this))
{
    conferenceModel->setTalkListData(QList<QString>());

    conferenceTableView->setModel(conferenceModel);
    conferenceTableView->horizontalHeader()->setStretchLastSection(true);

    mainLayout->addWidget(conferenceTableView);
    //mainLayout->addWidget(detailView);
    mainLayout->addWidget(backToFirstPageButton);
    setLayout(mainLayout);

    //dataFromConference->fetch();

    // connections


    connect(conferenceTableView, &QTableView::doubleClicked, this, &ConferenceListDetail::setDetailViewInfo);

    connect(backToFirstPageButton, &QPushButton::clicked, this, &ConferenceListDetail::leaveThisPage);
}

void ConferenceListDetail::conferenceData(QJsonObject headerConference, QJsonArray conferenceList)
{
    Q_UNUSED(headerConference);
    qDebug() << headerConference;
    conferenceJsonData.clear();
    //QList<QString> data;
    QList<QJsonValue> dataJson;
    detailView->setJsonData(conferenceList.at(0));
    for (int i = 0; i < conferenceList.size(); i++) {
        //data.append(conferenceList.at(i)["title"].toString());
        dataJson.append(conferenceList.at(i));
        conferenceJsonData.append(conferenceList.at(i));
    }
    //conferenceModel->setTalkListData(data);
    conferenceModel->setJsonTalkListData(dataJson);
}

void ConferenceListDetail::setConferenceInfo(QJsonValue conferenceInfo)
{
    qDebug() << "I am calling";
    if (conferenceInfo["title"].toString() == "tuebix")
        detailView = new TuebixDetailView(this);
    else
        detailView = new FosdemDetailView(this);
    mainLayout->insertWidget(1, detailView);
    dataFromConference = FactoryFormat::makeFormat("xml", conferenceInfo["url"].toString(), "schema", this);
    connect(dataFromConference, &DataFormat::conferenceChanged, this, &ConferenceListDetail::conferenceData);
    dataFromConference->fetch();
}

void ConferenceListDetail::setDetailViewInfo(const QModelIndex &index)
{
    detailView->setJsonData(conferenceJsonData.at(index.row()));
}

void ConferenceListDetail::leaveThisPage()
{
    mainLayout->removeWidget(detailView);
    delete detailView;
    emit backToMainPageClicked();
}
