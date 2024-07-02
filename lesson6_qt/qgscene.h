#ifndef QGSCENE_H
#define QGSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class qgscene : public QGraphicsScene
{
public:
    explicit qgscene(QObject *parent = nullptr);
};

#endif // QGSCENE_H
