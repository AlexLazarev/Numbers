#include "game.h"
#include <QGroupBox>

#include "fieldItem.h"
#include "button.h"
#include "score.h"
#include "timer.h"

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

    Timer *timer = new Timer();
    timer->setPos(430,0);

    FieldItem *field = new FieldItem(pictures); // Hm: mb wrong way, but...

    Button *updateButton = new Button(QString("Update"), 50, 20);
    Button *delButton = new Button(QString("Delete"), 50, 20);
    Button *helpButton = new Button(QString("Help"),50,20);



    updateButton->setPos(60,0);
    delButton->setPos(120,0);
    helpButton->setPos(180,0);


    connect(field,SIGNAL(valueChanged(int)),score,SLOT(increase(int)));
    connect(updateButton,SIGNAL(clicked()),field,SLOT(addCells()));
    connect(delButton,SIGNAL(clicked()),field,SLOT(delRow()));
    connect(helpButton,SIGNAL(clicked()),field,SLOT(help()));

    scene->addItem(field);
    scene->addItem(updateButton);
    scene->addItem(delButton);
    scene->addItem(helpButton);
    scene->addItem(score);
    scene->addItem(timer);

    setScene(scene);
}

Game::~Game(){
    delete scene;
    delete pictures;
}







