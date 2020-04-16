#ifndef CONFERENCESELECTION_H
#define CONFERENCESELECTION_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>
#include "../../models/conferenceselectiontablemodel.h"

class ConferenceSelection : public QWidget
{
    Q_OBJECT
public:
    explicit ConferenceSelection(QWidget *parent = nullptr);

signals:
    void conferenceSelected(QJsonValue conference);

public slots:
    void selectedConference(const QModelIndex& index);


private:
    ConferenceSelectionTableModel* conferencesTableModel;
    QTableView* conferencesTableView;
    QHBoxLayout* mainLayout;

};

#endif // CONFERENCESELECTION_H
