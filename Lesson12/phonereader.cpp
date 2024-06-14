#include "phonereader.h"

PhoneReader::PhoneReader(QString filename): filename(filename)
{

}

QVector<Phone> PhoneReader::read_all()
{
    QFile file(filename);

    if(!file.open(QFile::ReadOnly)) return {};

    QVector<Phone> phones;

    QTextStream ts(&file);
    QString line;
    Phone phone;

    while(!ts.atEnd()){
        line = ts.readLine();//Model: Galazy A50
        phone.model = line.sliced(7);

        line = ts.readLine();
        phone.brand = line.sliced(7);

        line = ts.readLine();
        phone.memory = line.sliced(8).toInt();

        line = ts.readLine();
        phone.ram = line.sliced(5).toInt();

        line = ts.readLine();

        phones.push_back(phone);
    }


    file.close();

    return phones;
}
