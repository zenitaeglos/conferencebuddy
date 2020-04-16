#include "conferenceselection.h"

ConferenceSelection::ConferenceSelection(QWidget *parent) : QWidget(parent),
    conferencesTableModel(new ConferenceSelectionTableModel),
    conferencesTableView(new QTableView),
    mainLayout(new QHBoxLayout)
{
    QList<QJsonValue> values;

    QJsonObject x;
    x["title"] = "tuebix";
    x["url"] = "https://www.tuebix.org/2019/giggity.xml";
    x["type"] = "xml";
    values.append(x);
    QJsonObject two;
    two["title"] = "fosdem";
    two["url"] = "https://fosdem.org/2020/schedule/xml";
    two["type"] = "xml";
    values.append(two);
    QJsonObject third;
    third["title"] = "Froscon";
    third["url"] = "https://programm.froscon.de/2019/schedule.xml";
    third["type"] = "xml";
    values.append(third);


    conferencesTableModel->setConferencesData(values);
    conferencesTableView->setModel(conferencesTableModel);

    conferencesTableView->horizontalHeader()->setStretchLastSection(true);

    mainLayout->addWidget(conferencesTableView);
    setLayout(mainLayout);

    connect(conferencesTableView, &QTableView::doubleClicked, this, &ConferenceSelection::selectedConference);
}

void ConferenceSelection::selectedConference(const QModelIndex &index)
{
    QJsonValue conference = conferencesTableModel->conferenceSelected(index.row());
    emit conferenceSelected(conference);
    qDebug() << conference;
}
