#include "button.h"



Button::Button(QString name,int width, int height, QGraphicsItem *parent):QGraphicsRectItem(parent){
    setRect(0,0,width,height);


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


    text->setOpacity(0.5);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event);


    text->setOpacity(1);
}

Button::~Button(){
    delete text;
}
