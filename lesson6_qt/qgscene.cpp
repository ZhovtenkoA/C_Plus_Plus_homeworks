#include "qgscene.h"

qgscene::qgscene(QObject *parent)
    : QGraphicsScene{parent}
{
    this->setSceneRect(0, 0, 200, 200);

    qreal x = 0, y = 0;
    qreal w = 25, h = 25;

    for (qint32 i= 0; i< 10; i++ ){
        QGraphicsRectItem* rect = new QGraphicsRectItem;

        rect->setRect(x, y, w, h);
        if(i<5){
            y += h;
        }

        else{
            x +=w;
        }


        rect->setBrush(QColor("blue"));
        addItem(rect);

    }




}
