#pragma once
#include <QGraphicsScene>
#include <fieldItem.h>
#include <button.h>

class GameScene : public QGraphicsScene
{

public:
    GameScene(QObject *parent = Q_NULLPTR);

    void wheelEvent(QGraphicsSceneWheelEvent *event);

private:
     FieldItem *field;
};

