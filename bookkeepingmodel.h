#ifndef BOOKKEEPINGMODEL_H
#define BOOKKEEPINGMODEL_H

#include <QAbstractListModel>

class BookkeepingList;

class BookkeepingModel : public QAbstractListModel
{
    Q_OBJECT

public:
    Q_PROPERTY(BookkeepingList *list READ setList WRITE setList)
    static constexpr size_t DEFAULT_LIST_SIZE {30};

    enum {
        DoneRole = Qt::UserRole,
        DescriptionRole
    };

    explicit BookkeepingModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index,  const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    BookkeepingList* list() const;
    void setList(BookkeepingList *list);

private:
    BookkeepingList *m_list;

}

#endif // BOOKKEEPINGMODEL_H
