#pragma once
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include "field.h"
#include "gamemanager.h"
#include "images.h"

class GraphicsField : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    GraphicsField(Images *p);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void addCells();
    void delRow();


protected:


private:
    QImage getFieldImage();
    Field *field;
    GameManager *gm;
    Images *pictures;
};

