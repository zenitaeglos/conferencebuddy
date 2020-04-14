#include "conferencetablemodel.h"

ConferenceTableModel::ConferenceTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int ConferenceTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return talksJsonList.count();
}

int ConferenceTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant ConferenceTableModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    return talksJsonList.at(index.row())["title"];
}

QVariant ConferenceTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);
    return QVariant();
}

void ConferenceTableModel::setTalkListData(QList<QString> data)
{
    beginResetModel();
    talksList = data;
    endResetModel();
}

void ConferenceTableModel::setJsonTalkListData(QList<QJsonValue> data)
{
    beginResetModel();
    talksJsonList = data;
    endResetModel();

}
