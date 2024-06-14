#include "phonesaver.h"

PhoneSaver::PhoneSaver(const QString& filename): filename(filename)
{

}

void PhoneSaver::save(const Phone &phone)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Append)) return;

    QTextStream ts(&file);
    ts << "Model: " << phone.model << "\n";
    ts << "Brand: " << phone.brand << "\n";
    ts << "Memory: " << phone.memory << "\n";
    ts << "RAM: " << phone.ram << "\n\n";

    file.close();
}
