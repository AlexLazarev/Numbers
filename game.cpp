#include "game.h"
#include <QGroupBox>

#include "fieldItem.h"
#include "button.h"
#include "score.h"
#include "timer.h"

#include "gamescene.h"


Game::Game(QWidget *parent):QGraphicsView(parent){

   setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

   scene = new QGraphicsScene();

   gamescene = new GameScene();

   pictures = new Images();
   pictures->load();


   QBrush brush;
   brush.setTextureImage(pictures->getImage("background"));


   scene->setBackgroundBrush(brush);

   setScene(scene);

}

void Game::showMenu(){
    scene->clear();

    scene->setSceneRect(0,0,WINDOW_WIDTH-5,WINDOW_HEIGHT-10);



    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("NUMBERS"));
    QFont titleFont("comic sans", 50);

    titleText->setFont(titleFont);

    int tx = this->width()/2 - titleText->boundingRect().width()/2;
    int ty = 160;

    titleText->setPos(tx,ty);


    Button *playButton = new Button(QString("PLAY"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *exitButton = new Button(QString("EXIT"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);

    int bx = this->width()/2 - playButton->boundingRect().width()/2;
    int by = 260;

    playButton->setPos(bx,by);
    exitButton->setPos(bx,by+80);


    connect(playButton,SIGNAL(clicked()),this,SLOT(showGame()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));


    scene->addItem(titleText);
    scene->addItem(playButton);
    scene->addItem(exitButton);



}



void Game::showGame(){
    scene->clear();
    setScene(gamescene);
}

void Game::showGameOver(){
    setScene(gamescene);

}


Game::~Game(){
    delete scene;
    delete pictures;
}







