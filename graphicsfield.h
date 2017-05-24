#ifndef GRAPHICSFIELD_H
#define GRAPHICSFIELD_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "field.h"
#include "gamemanager.h"
#include "images.h"

class GraphicsField : public QGraphicsItem
{
public:
    GraphicsField(Images *p);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:
    QImage getFieldImage();
    Field *field;
    GameManager *gm;
    Images *pictures;
};

#endif // GRAPHICSFIELD_H
