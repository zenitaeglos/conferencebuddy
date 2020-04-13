#include "conferencetablemodel.h"

ConferenceTableModel::ConferenceTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ConferenceTableModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

int ConferenceTableModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ConferenceTableModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

QVariant ConferenceTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
