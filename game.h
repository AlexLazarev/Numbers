#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>


#include "images.h"
#include "gamescene.h"


class Game : public QGraphicsView
{
    Q_OBJECT


public:
    Game(QWidget * parent = NULL);
    ~Game();



public slots:
    void showMenu();  
    void showGame();
    void showGameOver();

private:
    GameScene *gamescene;
    QGraphicsScene *scene;
    Images *pictures;
};

