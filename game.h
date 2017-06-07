#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>


#include "gamescene.h"
#include "menuscene.h"
#include "gameoverscene.h"
class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = NULL);
    ~Game();



public slots:
    void showMenu();  
    void showGame();

    void showNewGame();

    void showGameOver();

private:
    GameScene *gamescene;
    MenuScene *menuscene;
    GameOverScene *gameoverscene;

};

