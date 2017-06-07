#include "game.h"
#include <QGroupBox>
#include "fieldItem.h"
#include "button.h"
#include "score.h"
#include "timer.h"

#include "gamescene.h"
#include "images.h"

Game::Game(QWidget *parent):QGraphicsView(parent){

   setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

   setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
   setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

   Images::getInstance()->load();

   menuscene = new MenuScene();



   gameoverscene = new GameOverScene();

   showMenu();
}

void Game::showMenu(){

    setScene(menuscene);

    connect(menuscene,SIGNAL(toGame()),this,SLOT(showNewGame()));
    connect(menuscene,SIGNAL(toExit()),this,SLOT(close()));

}



void Game::showGame(){

    setScene(gamescene);

    connect(gamescene,SIGNAL(toMenu()),this,SLOT(showMenu()));
    connect(gamescene,SIGNAL(toGameOver()),this,SLOT(showGameOver()));
}

void Game::showNewGame(){
    GameScene *gs = new GameScene();

    gamescene = gs;

    setScene(gs);

    connect(gs,SIGNAL(toMenu()),this,SLOT(showMenu()));
    connect(gs,SIGNAL(toGameOver()),this,SLOT(showGameOver()));


}

void Game::showGameOver(){

    setScene(gameoverscene);

    connect(gameoverscene,SIGNAL(toReplay()),this,SLOT(showNewGame()));
    connect(gameoverscene,SIGNAL(toExit()),this,SLOT(close()));

}


Game::~Game(){
    delete gamescene;
    delete menuscene;
    delete gameoverscene;

}







