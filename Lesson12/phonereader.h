#ifndef PHONEREADER_H
#define PHONEREADER_H

#include "phone.h"
#include <QFile>
#include <QTextStream>
#include <QVector>

class PhoneReader
{
    QString filename;
public:
    PhoneReader(QString filename);

    QVector<Phone> read_all();

};

#endif // PHONEREADER_H
