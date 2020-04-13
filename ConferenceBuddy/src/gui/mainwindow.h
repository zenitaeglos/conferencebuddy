#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtCore/QJsonObject>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QWidget>
#include <QStackedLayout>
#include "dataconference/dataformat.h"
#include "dataconference/dataxmlformat.h"
#include "dataconference/datajsonformat.h"
#include "dataconference/factoryformat.h"
#include "detailview/detailviewfactory.h"
#include "detailview/detailview.h"
#include "detailview/tuebix/tuebixdetailview.h"
#include "detailview/fosdem/fosdemdetailview.h"

#include "listconferences/conferencelistdetail.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void setupUI();

signals:

public slots:
    void conferenceData(QJsonObject headerConference, QJsonArray conferenceList);

    //change detail slot
    void changeDetailView();

private:
    DataFormat* dataFormat;
    DataFormat* xmData;
    DetailView* detailViewConference;

    QWidget* mainWidget;
    QHBoxLayout* horizontalLayout;
    QStackedLayout* mainStackLayout;
    ConferenceListDetail* conferenceListDetail;

};

#endif // MAINWINDOW_H
