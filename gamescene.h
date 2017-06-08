#pragma once
#include <QGraphicsScene>
#include <fieldItem.h>

#include "score.h"
#include "timer.h"
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = NULL);
    ~GameScene();

    void init(QString mode);

    void wheelEvent(QGraphicsSceneWheelEvent *event);

signals:
    void toMenu();
    void toGameOver();

public slots:
    void GameOver();

private:
     FieldItem *field;
     Score *score;
     Timer *timer;
};

