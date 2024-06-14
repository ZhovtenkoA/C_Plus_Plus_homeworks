#ifndef PHONESAVER_H
#define PHONESAVER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include "phone.h"

class PhoneSaver
{
    QString filename;
public:
    PhoneSaver(const QString& filename);

    void save(const Phone& phone);
};

#endif // PHONESAVER_H
