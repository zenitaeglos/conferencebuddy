#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>

class DetailView : public QWidget
{
    Q_OBJECT
public:
    explicit DetailView(QWidget *parent = nullptr);

    virtual QString viewName() = 0;

    virtual void setJsonData(QJsonValue data) = 0;

signals:

};

#endif // DETAILVIEW_H
