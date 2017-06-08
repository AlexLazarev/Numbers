#include "game.h"
#include <time.h>
#include <QGroupBox>
#include "fieldItem.h"
#include "button.h"
#include "score.h"
#include "timer.h"

#include "gamescene.h"
#include "images.h"

Game::Game(QWidget *parent):QGraphicsView(parent){
   srand(time(0));

   setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

   setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
   setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

   Images::getInstance()->load();

   menuscene = new MenuScene();

   gamescene = new GameScene();

   gameoverscene = new GameOverScene();

   showMenu();

   connect(menuscene,SIGNAL(toClassicGame()),this,SLOT(showClassicGame()));
   connect(menuscene,SIGNAL(toRandomGame()),this,SLOT(showRandomGame()));
   connect(menuscene,SIGNAL(toExit()),this,SLOT(close()));

   connect(gamescene,SIGNAL(toMenu()),this,SLOT(showMenu()));
   connect(gamescene,SIGNAL(toGameOver()),this,SLOT(showGameOver()));

   connect(gameoverscene,SIGNAL(toMenu()),this,SLOT(showMenu()));
   connect(gameoverscene,SIGNAL(toGame()),this,SLOT(showGame()));
}

void Game::showMenu(){

    setScene(menuscene);

}



void Game::showGame(){
    setScene(gamescene);
}



void Game::showClassicGame(){
    gamescene->init("CLASSIC");
    setScene(gamescene);
}

void Game::showRandomGame(){
    gamescene->init("RANDOM");
    setScene(gamescene);
}


void Game::showGameOver(){

    gameoverscene->init();

    setScene(gameoverscene);

}


Game::~Game(){
    delete gamescene;
    delete menuscene;
    delete gameoverscene;

}







