#pragma once
#include <QGraphicsScene>
#include <fieldItem.h>
#include <button.h>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = NULL);
    ~GameScene();

    void wheelEvent(QGraphicsSceneWheelEvent *event);

signals:
    void toMenu();
    void toGameOver();


private:
     FieldItem *field;
};

