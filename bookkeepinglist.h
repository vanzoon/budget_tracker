#ifndef BOOKKEEPINGLIST_H
#define BOOKKEEPINGLIST_H

#include <QObject>
#include <QVector>

class BookkeepingList : public QObject
{
    Q_OBJECT
public:
    explicit BookkeepingList(QObject *parent = nullptr);

    struct Entry {
        bool done;
        QString description;
    };

    QVector<Entry> items() const;

    bool setEntryAt(int index, const Entry &entry);

signals:
    void preEntryAppended();
    void postEntryAppended();

    void preEntryRemoved(int index);
    void postEntryRemoved();

public slots:
    void appendEntry();
    void removeCompletedEntries();

private:
    QVector<Entry> m_list;

};

#endif // BOOKKEEPINGLIST_H
