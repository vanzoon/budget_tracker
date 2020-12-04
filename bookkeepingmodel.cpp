#include <QVector>
#include "bookkeepingmodel.h"
#include "bookkeepinglist.h"

BookkeepingModel::BookkeepingModel(QObject *parent)
    : QAbstractListModel(parent),
      m_list(nullptr)
{
}

int BookkeepingModel::rowCount(const QModelIndex &parent) const
{
    /* for list models (only root node/ invalid parent) should return
     * the list's size, for all other(valid) parents - return 0 so that
     * doesn't become a tree model.
    */
    if (parent.isValid())
        return 0;

    return DEFAULT_LIST_SIZE;
}


QVariant BookkeepingModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
    case DoneRole:
        return QVariant(false);
    case DescriptionRole:
        return QVariant(QStringLiteral("Test descr"));
    }

    return QVariant();
}

bool BookkeepingModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
   if (data(index, role) != value)
   {
       emit dataChanged(index, index, QVector<int>() << role);
       return true;
   }
   return false;
}

Qt::ItemFlags BookkeepingModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> BookkeepingModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DoneRole] = "done";
    names[DescriptionRole] = "description";
    return names;
}

BookkeepingList* BookkeepingModel::list() const
{
    return m_list;
}

void BookkeepingModel::setList(BookkeepingList *list)
{
    beginResetModel();

    if (m_list)
        m_list->disconnect(this);

    m_list = list;
    if (m_list)
        connect(m_list, &BookkeepingList::preEntryAppended,
                this, [=]() {
            const int index = m_list->items().size();
            beginInsertRows(QModelIndex(), index, index);
        })
}
