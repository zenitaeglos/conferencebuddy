#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "dataconference/dataformat.h"
#include "dataconference/dataxmlformat.h"
#include "dataconference/datajsonformat.h"
#include "dataconference/factoryformat.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
    DataFormat* dataFormat;
    DataFormat* xmData;
};

#endif // MAINWINDOW_H
