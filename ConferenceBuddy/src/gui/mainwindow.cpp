#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    xmlData(new DataXmlFormat())
{
    xmlData->fetch();
}
