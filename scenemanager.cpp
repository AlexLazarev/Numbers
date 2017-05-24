#include "scenemanager.h"
#include <graphicsfield.h>

#include "button.h"

SceneManager::SceneManager(QWidget *parent){

   setFixedSize(WINDOW_HEIGHT,WINDOW_WIDTH);

   scene = new QGraphicsScene();


   scene->setSceneRect(0,0,WINDOW_HEIGHT-10,WINDOW_WIDTH-10);


   pictures = new Images();
   pictures->load();

   setScene(scene);

}

void SceneManager::showMenu(){
    scene->clear();

    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("NUMBERS"));
    QFont titleFont("comic sans", 50);

    titleText->setFont(titleFont);

    int tx = this->width()/2 - titleText->boundingRect().width()/2;
    int ty = 160;

    titleText->setPos(tx,ty);


    Button *playButton = new Button(QString("PLAY"));
    Button *exitButton = new Button(QString("EXIT"));

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

void SceneManager::showGame(){
    scene->clear();

    GraphicsField *fieldItem = new GraphicsField(pictures);
    scene->addItem(fieldItem);

    setScene(scene);
}

SceneManager::~SceneManager(){
    delete scene;
    delete pictures;
}







