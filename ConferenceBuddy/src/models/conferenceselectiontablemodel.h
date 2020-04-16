#ifndef CONFERENCESELECTIONTABLEMODEL_H
#define CONFERENCESELECTIONTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QJsonValue>


class ConferenceSelectionTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ConferenceSelectionTableModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex& parent) const override;
    virtual int columnCount(const QModelIndex& parent) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setConferencesData(QList<QJsonValue> data);

    QJsonValue conferenceSelected(int position);

signals:


private:
    QList<QJsonValue> conferences;

};

#endif // CONFERENCESELECTIONTABLEMODEL_H
