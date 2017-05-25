#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Button(QString name, int width, int height, QGraphicsItem *parent = NULL);
    ~Button();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem *text;
    QBrush brush;

};


