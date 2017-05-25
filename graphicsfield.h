#pragma once
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include "field.h"
#include "gamemanager.h"
#include "images.h"

class GraphicsField : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    GraphicsField(Images *p);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent*);


public slots:
    void addCells();


protected:


private:
    QImage getFieldImage();
    Field *field;
    GameManager *gm;
    Images *pictures;
};

