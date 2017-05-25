#include "game.h"
#include <graphicsfield.h>

#include "button.h"

Game::Game(QWidget *parent):QGraphicsView(parent){

   setFixedSize(WINDOW_HEIGHT,WINDOW_WIDTH);

   scene = new QGraphicsScene();


   scene->setSceneRect(0,0,WINDOW_HEIGHT-10,WINDOW_WIDTH-10);


   pictures = new Images();
   pictures->load();



   setScene(scene);

}

void Game::showMenu(){
    scene->clear();

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

    GraphicsField *fieldItem = new GraphicsField(pictures);

    Button *updateButton = new Button(QString("Update"),50,20);
    updateButton->setPos(100,0);


    connect(updateButton,SIGNAL(clicked()),fieldItem,SLOT(addCells()));


    scene->addItem(fieldItem);
    scene->addItem(updateButton);
    setScene(scene);
}

Game::~Game(){
    delete scene;
    delete pictures;
}







