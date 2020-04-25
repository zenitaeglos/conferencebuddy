#ifndef TUEBIXVIEW_H
#define TUEBIXVIEW_H

#include <QObject>
#include <QWidget>
#include <QJsonValue>
#include <QLabel>
#include <QVBoxLayout>

class TuebixView : public QWidget
{
    Q_OBJECT
public:
    explicit TuebixView(QWidget *parent = nullptr);
    explicit TuebixView(QJsonValue talkInformation, QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout* mainLayout;
    QLabel* titleLabel;

};

#endif // TUEBIXVIEW_H
