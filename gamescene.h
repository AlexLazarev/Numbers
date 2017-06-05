#pragma once
#include <QGraphicsScene>
#include <fieldItem.h>
#include <button.h>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = 0);

    void wheelEvent(QGraphicsSceneWheelEvent *event);

signals:
    void toMenu();
    void toGameOver();


private:
     FieldItem *field;
};

