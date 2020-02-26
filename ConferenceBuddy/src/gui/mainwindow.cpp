#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    dataFormat(FactoryFormat::makeFormat("json", "https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2", "schema", this)),
    xmData(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this))
    //xmData(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", parent))
    //xmData(FactoryFormat::makeFormat("giggity", "https://programm.froscon.de/2019/schedule.xml", this))
{
    dataFormat->fetch();
    xmData->fetch();
    // https://fosdem.org/2020/schedule/xml
    connect(xmData, &DataFormat::headerChanged, this, &MainWindow::headerConference);
}

void MainWindow::headerConference(QJsonObject headerConferenceInformation)
{
    qInfo() << "poj claro" << headerConferenceInformation;
}
