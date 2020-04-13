#include "conferencetablemodel.h"

ConferenceTableModel::ConferenceTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ConferenceTableModel::rowCount(const QModelIndex &parent) const
{
    return talksList.count();
}

int ConferenceTableModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ConferenceTableModel::data(const QModelIndex &index, int role) const
{
    return talksList.at(index.row());
}

QVariant ConferenceTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

void ConferenceTableModel::setTalkListData(QList<QString> data)
{
    beginResetModel();
    talksList = data;
    endResetModel();
}
