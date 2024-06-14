#include "save_items.h"

ItemsSaver::ItemsSaver(const QString& filename): filename(filename)
{

}

void ItemsSaver::save(const Items &item)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Append)) return;

    QTextStream ts(&file);
    ts << "Name: " << item.name << "\n";
    ts << "Price: " << item.price << "\n";
    ts << "Weight: " << item.weight << "\n\n";

    file.close();
}
