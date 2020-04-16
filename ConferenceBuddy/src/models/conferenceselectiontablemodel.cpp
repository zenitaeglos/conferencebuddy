#include "conferenceselectiontablemodel.h"

ConferenceSelectionTableModel::ConferenceSelectionTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ConferenceSelectionTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return conferences.count();
}

int ConferenceSelectionTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant ConferenceSelectionTableModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    return conferences.at(index.row())["title"];
}

QVariant ConferenceSelectionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
        if (orientation == Qt::Horizontal)
            return "Conferences";
    return QVariant();
}

void ConferenceSelectionTableModel::setConferencesData(QList<QJsonValue> data)
{
    conferences = data;
}
