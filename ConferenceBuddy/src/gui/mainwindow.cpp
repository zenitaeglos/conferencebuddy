#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    dataFormat(FactoryFormat::makeFormat("json", "https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2", "schema", this)),
    //xmData(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this)),
    //xmData(FactoryFormat::makeFormat("giggity", "https://programm.froscon.de/2019/schedule.xml", this)),
    xmData(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", this)),
    //detailViewConference(DetailViewFactory::makeDetailView("fosdem")),
    detailViewConference(DetailViewFactory::makeDetailView("tuebix")),
    mainWidget(new QWidget(this)),
    horizontalLayout(new QHBoxLayout),
    mainStackLayout(new QStackedLayout),
    conferenceListDetail(new ConferenceListDetail(this))
{

    dataFormat->fetch();
    xmData->fetch();
    // https://fosdem.org/2020/schedule/xml
    //xmData(FactoryFormat::makeFormat("giggity", "https://fosdem.org/2020/schedule/xml", parent))
    //xmData(FactoryFormat::makeFormat("giggity", "https://programm.froscon.de/2019/schedule.xml", this))
    connect(xmData, &DataFormat::conferenceChanged, this, &MainWindow::conferenceData);
    //connect(buttonChangeDetail, &QPushButton::clicked, this, &MainWindow::changeDetailView);

    setupUI();
}

void MainWindow::setupUI()
{
    //buttonChangeDetail->setText("Change detail");
    //horizontalLayout->addWidget(detailViewConference);
    //horizontalLayout->addWidget(buttonChangeDetail);
    mainStackLayout->addWidget(detailViewConference);
    mainStackLayout->addWidget(conferenceListDetail);
    mainStackLayout->setCurrentIndex(1);

    //mainWidget->setLayout(horizontalLayout);
    mainWidget->setLayout(mainStackLayout);

    setGeometry(100, 100, 500, 400);

    setCentralWidget(mainWidget);
}

void MainWindow::conferenceData(QJsonObject headerConference, QJsonArray conferenceList)
{
    //Q_UNUSED(headerConference);
    qDebug() << headerConference;

    qDebug() << conferenceList.at(0);
    //qDebug() << conferenceList.size();
    detailViewConference->setJsonData(conferenceList.at(2));
}

void MainWindow::changeDetailView()
{   
    /*
    if (detailViewConference->viewName() == "fosdem") {
        qDebug() << detailViewConference << detailViewConference->viewName() << detailViewConference->metaObject();

        QWidget* element = horizontalLayout->itemAt(0)->widget();

        horizontalLayout->removeWidget(element);
        delete element;
        detailViewConference = DetailViewFactory::makeDetailView("tuebix");
        horizontalLayout->insertWidget(0, detailViewConference);


    }
    else if (detailViewConference->viewName() == "tuebix") {
        qDebug() << detailViewConference << detailViewConference->viewName() << detailViewConference->metaObject();
        QWidget* element = horizontalLayout->itemAt(0)->widget();
        horizontalLayout->removeWidget(element);
        delete element;
        detailViewConference = DetailViewFactory::makeDetailView("fosdem");
        horizontalLayout->insertWidget(0, detailViewConference);
    }
    */
}

