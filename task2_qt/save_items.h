#ifndef SAVE_ITEMS_H
#define SAVE_ITEMS_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include "items.h"

class ItemsSaver
{
    QString filename;
public:
    ItemsSaver(const QString& filename);

    void save(const Items& item);
};

#endif // SAVE_ITEMS_H
