#include "gamescene.h"
#include "images.h"
#include "defines.h"
#include "button.h"
#include "timer.h"
#include "score.h"

GameScene::GameScene(QObject * parent):QGraphicsScene(parent){
    setSceneRect(0,0,WINDOW_WIDTH-5, WINDOW_HEIGHT-10);

    Images *pictures = new Images();

    pictures->load();

    QBrush brush;
    brush.setTextureImage(pictures->getImage("background"));

    setBackgroundBrush(brush);





    Score *score = new Score();
    score->setPos(300,0);

    Timer *timer = new Timer();
    timer->setPos(430,0);

    field = new FieldItem(pictures); // Hm: mb wrong way, but...

    Button *updateButton = new Button(QString("Update"), 50, 20);
    Button *delButton = new Button(QString("Delete"), 50, 20);
    Button *helpButton = new Button(QString("Help"),50,20);



    updateButton->setPos(50,10);
    delButton->setPos(120,10);
    helpButton->setPos(190,10);


    connect(field,SIGNAL(valueChanged(int)),score,SLOT(increase(int)));
    connect(updateButton,SIGNAL(clicked()),field,SLOT(addCells()));
    connect(delButton,SIGNAL(clicked()),field,SLOT(delRow()));
    connect(helpButton,SIGNAL(clicked()),field,SLOT(help()));


    addItem(field);
    addItem(updateButton);
    addItem(delButton);
    addItem(helpButton);
    addItem(score);
    addItem(timer);
}


void GameScene::wheelEvent(QGraphicsSceneWheelEvent *event){
    if(event->delta() < 0)
        field->moveUp();
    else
        field->moveDown();
}
