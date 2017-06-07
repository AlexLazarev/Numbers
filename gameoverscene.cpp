#include "gameoverscene.h"
#include <QGraphicsTextItem>

#include "defines.h"
#include "button.h"
#include "images.h"

GameOverScene::GameOverScene(QObject *parent):QGraphicsScene(parent){

    setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);


    QBrush brush;
    brush.setTextureImage( Images::getInstance()->getImage("background"));

    setBackgroundBrush(brush);



    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("GAME OVER"));
    QFont titleFont("comic sans", 50);

    titleText->setFont(titleFont);

    int tx = this->width()/2 - titleText->boundingRect().width()/2;
    int ty = 160;

    titleText->setPos(tx,ty);


    Button *playButton = new Button(QString("REPLAY"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *exitButton = new Button(QString("EXIT"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);

    int bx = this->width()*0.35 - playButton->boundingRect().width()/2;
    int by = 260;

    playButton->setPos(bx,by);
    exitButton->setPos(bx + MENU_BUTTON_WIDTH + 40,by);


    connect(playButton,SIGNAL(clicked()),this,SIGNAL(toReplay()));
    connect(exitButton,SIGNAL(clicked()),this,SIGNAL(toExit()));


    addItem(titleText);
    addItem(playButton);
    addItem(exitButton);

}
