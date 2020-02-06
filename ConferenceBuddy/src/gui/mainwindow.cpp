#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    dataFormat(FactoryFormat::makeFormat("json", "https://api.astrocats.space/catalog?ra=21:23:32.16&dec=-53:01:36.08&radius=2", "schema", this)),
    xmData(FactoryFormat::makeFormat("xml", "https://www.tuebix.org/2019/giggity.xml", "schema", this))
{
    dataFormat->fetch();
    xmData->fetch();
}
