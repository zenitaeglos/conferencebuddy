#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtCore/QJsonObject>
#include "dataconference/dataformat.h"
#include "dataconference/dataxmlformat.h"
#include "dataconference/datajsonformat.h"
#include "dataconference/factoryformat.h"
#include "detailview/detailviewfactory.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void conferenceData(QJsonObject headerConference, QJsonArray conferenceList);

private:
    DataFormat* dataFormat;
    DataFormat* xmData;
    DetailViewFactory* factory;
};

#endif // MAINWINDOW_H
