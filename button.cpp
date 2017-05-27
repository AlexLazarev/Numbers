#include "button.h"



Button::Button(QString name,int width, int height, QGraphicsItem *parent):QGraphicsRectItem(parent){
    setRect(0,0,width,height);

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(x,y);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event);
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event);

    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event);

    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

Button::~Button(){
    delete text;
}
