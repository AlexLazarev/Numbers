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


   Images::getInstance()->load();

   menuscene = new MenuScene();

   gamescene = new GameScene();


   showMenu();
}

void Game::showMenu(){

    setScene(menuscene);

    connect(menuscene,SIGNAL(toGame()),this,SLOT(showGame()));
    connect(menuscene,SIGNAL(toExit()),this,SLOT(close()));

}



void Game::showGame(){


    setScene(gamescene);

    connect(gamescene,SIGNAL(toMenu()),this,SLOT(showMenu()));
}

void Game::showGameOver(){


}


Game::~Game(){
    delete gamescene;
    delete menuscene;

}







