#include "conferenceselection.h"

ConferenceSelection::ConferenceSelection(QWidget *parent) : QWidget(parent),
    conferencesTableModel(new ConferenceSelectionTableModel),
    conferencesTableView(new QTableView),
    mainLayout(new QHBoxLayout)
{
    QList<QJsonValue> values;

    QJsonObject x;
    x["title"] = "one";
    values.append(x);
    QJsonObject two;
    two["title"] = "two";
    values.append(two);


    conferencesTableModel->setConferencesData(values);
    conferencesTableView->setModel(conferencesTableModel);

    mainLayout->addWidget(conferencesTableView);
    setLayout(mainLayout);
}
