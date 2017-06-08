#pragma once
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "field.h"
#include "gamemanager.h"
#include "images.h"
#include "score.h"

class FieldItem : public QGraphicsObject
{
    Q_OBJECT

public:
    FieldItem(QString mode);
    ~FieldItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void moveUp();
    void moveDown();

    void init(QString mode);


public slots:
    void help();
    void addCells();
    void back();

signals:
    void valueChanged(int);
    void gameOver();

protected:


private:
    int height;

    QImage image;

    void updateImage();

    Field *field;
    GameManager *gm;


};

