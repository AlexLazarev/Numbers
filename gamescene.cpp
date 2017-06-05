#include "gamescene.h"
#include "images.h"
#include "defines.h"
#include "button.h"
#include "timer.h"
#include "score.h"
#include "panel.h"
#include "images.h"
#include <QGraphicsPixmapItem>

GameScene::GameScene(QObject * parent):QGraphicsScene(parent){
    setSceneRect(5,5,WINDOW_WIDTH-5, WINDOW_HEIGHT-10);


    QBrush brush;
    brush.setTextureImage(Images::getInstance()->getImage("background"));

    setBackgroundBrush(brush);


    Panel *panel = new Panel();


    Score *score = new Score();
    score->setPos(330,5);

    Timer *timer = new Timer();
    timer->setPos(500,5);

    QGraphicsPixmapItem *pixmapTimer = new  QGraphicsPixmapItem(QPixmap(":/images/img/timer.png"));
    pixmapTimer->setPos(470,5);

    field = new FieldItem();

    Button *updateButton = new Button(QString("Update"), 50, 20);
    Button *delButton = new Button(QString("Delete"), 50, 20);
    Button *helpButton = new Button(QString("Help"), 50, 20);
    Button *menuButton = new Button(QString("Menu"), 50, 20);



    panel->setPos(0,0);
    menuButton->setPos(30,12);
    updateButton->setPos(100,12);
    delButton->setPos(170,12);
    helpButton->setPos(240,12);


    connect(field,SIGNAL(valueChanged(int)),score,SLOT(increase(int)));
    connect(menuButton,SIGNAL(clicked()),this,SIGNAL(toMenu()));
    connect(updateButton,SIGNAL(clicked()),field,SLOT(addCells()));
    connect(delButton,SIGNAL(clicked()),field,SLOT(delRow()));
    connect(helpButton,SIGNAL(clicked()),field,SLOT(help()));

    addItem(field);
    addItem(panel);
    addItem(menuButton);
    addItem(pixmapTimer);
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

