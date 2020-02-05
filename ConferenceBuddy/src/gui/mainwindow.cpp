#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    xmlData(new DataJsonFormat(this))
{
    xmlData->fetch();
}
