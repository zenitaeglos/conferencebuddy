#include "conferenceselectiontablemodel.h"

ConferenceSelectionTableModel::ConferenceSelectionTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ConferenceSelectionTableModel::rowCount(const QModelIndex &parent) const
{
    return conferences.count();
}

int ConferenceSelectionTableModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ConferenceSelectionTableModel::data(const QModelIndex &index, int role) const
{
    return conferences.at(index.row())["title"];
}

QVariant ConferenceSelectionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

void ConferenceSelectionTableModel::setConferencesData(QList<QJsonValue> data)
{
    conferences = data;
}
