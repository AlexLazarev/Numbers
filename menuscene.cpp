#include "menuscene.h"
#include <QGraphicsTextItem>

#include "defines.h"
#include "button.h"
#include "images.h"

MenuScene::MenuScene(QObject *parent):QGraphicsScene(parent){

    setSceneRect(0,0,WINDOW_WIDTH-5,WINDOW_HEIGHT-10);


    QBrush brush;
    brush.setTextureImage( Images::getInstance()->getImage("background"));

    setBackgroundBrush(brush);



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


    connect(playButton,SIGNAL(clicked()),this,SIGNAL(toGame()));
    connect(exitButton,SIGNAL(clicked()),this,SIGNAL(toExit()));


    addItem(titleText);
    addItem(playButton);
    addItem(exitButton);

}
