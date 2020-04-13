#ifndef CONFERENCETABLEMODEL_H
#define CONFERENCETABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>

class ConferenceTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ConferenceTableModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex& parent) const override;
    virtual int columnCount(const QModelIndex& parent) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

signals:

};

#endif // CONFERENCETABLEMODEL_H
