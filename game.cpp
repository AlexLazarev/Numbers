#include "game.h"
#include <graphicsfield.h>
#include <QGroupBox>

#include "button.h"
#include "score.h"

Game::Game(QWidget *parent):QGraphicsView(parent){

   setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

   scene = new QGraphicsScene();







   pictures = new Images();
   pictures->load();



   setScene(scene);

}

void Game::showMenu(){
    scene->clear();



    scene->setSceneRect(0,0,WINDOW_WIDTH-10,WINDOW_HEIGHT-10);

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

    scene->setSceneRect(0,0,WINDOW_WIDTH-20,MAX_HEIGHT);

    Score *score = new Score();
    score->setPos(300,0);


    GraphicsField *fieldItem = new GraphicsField(pictures);

    Button *updateButton = new Button(QString("Update"), 50, 20);
    Button *delButton = new Button(QString("Delete"), 50, 20);
    updateButton->setPos(100,0);
    delButton->setPos(160,0);




    connect(updateButton,SIGNAL(clicked()),fieldItem,SLOT(addCells()));
    connect(delButton,SIGNAL(clicked()),fieldItem,SLOT(delRow()));

    scene->addItem(fieldItem);
    scene->addItem(updateButton);
    scene->addItem(delButton);
    scene->addItem(score);
    setScene(scene);
}

Game::~Game(){
    delete scene;
    delete pictures;
}







