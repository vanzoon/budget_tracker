#include "bookkeepinglist.h"

BookkeepingList::BookkeepingList(QObject *parent)
    : QObject(parent),
      m_list {{true, QStringLiteral("meow")}, {false, QStringLiteral("not meow")}}
{

}

QVector<BookkeepingList::Entry> BookkeepingList::items() const
{
    return m_list;
}

bool BookkeepingList::setEntryAt(int index, const BookkeepingList::Entry &new_entry)
{
   if (index < 0 || index >= m_list.size())
       return false;

   const Entry &oldEntry = m_list.at(index);
   if (oldEntry.done == new_entry.done &&
           oldEntry.description == new_entry.description)
       return false;

   m_list[index] = new_entry;
   return true;
}

void BookkeepingList::appendEntry()
{
    emit preEntryAppended();

    Entry new_entry;
    new_entry.done = false;
    m_list.append(new_entry);

    emit postEntryAppended();
}

void BookkeepingList::removeCompletedEntries()
{
    for (uint8_t i=0; i<m_list.length(); ++i) {
        if (m_list[i].done) {
            emit preEntryRemoved(i);

            m_list.removeAt(i);

            emit postEntryRemoved();
        }
    }
}
