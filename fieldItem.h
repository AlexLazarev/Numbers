#pragma once
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include "field.h"
#include "gamemanager.h"
#include "images.h"
#include "score.h"

class FieldItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    FieldItem(Images *p);
    ~FieldItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void help();
    void addCells();
    void delRow();

signals:
    void valueChanged(int);


protected:


private:
    QImage getFieldImage();
    Field *field;
    GameManager *gm;
    Images *pictures;

};

