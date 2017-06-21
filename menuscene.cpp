#include "menuscene.h"
#include <QGraphicsTextItem>

#include "defines.h"
#include "button.h"
#include "images.h"

MenuScene::MenuScene(QObject *parent):QGraphicsScene(parent){

    setSceneRect(0,0,WINDOW_WIDTH-3,WINDOW_HEIGHT-3);


    QBrush brush;
    brush.setTextureImage( Images::getInstance()->getImage("background"));

    setBackgroundBrush(brush);



    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("NUMBERS"));
    QFont titleFont("comic sans", 50);

    titleText->setFont(titleFont);

    int tx = this->width()/2 - titleText->boundingRect().width()/2;
    int ty = 160;

    titleText->setPos(tx,ty);


    Button *registerButton = new Button(QString("SIGN IN"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *playButton = new Button(QString("CLASSIC"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *randomButton = new Button(QString("RANDOM"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *exitButton = new Button(QString("EXIT"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);

    int bx = this->width()/2 - playButton->boundingRect().width()/2;
    int by = 260;

    registerButton->setPos(bx,by+240);
    playButton->setPos(bx,by);
    randomButton->setPos(bx,by+80);
    exitButton->setPos(bx,by+160);


    connect(playButton,SIGNAL(clicked()),this,SIGNAL(toClassicGame()));
    connect(randomButton,SIGNAL(clicked()),this,SIGNAL(toRandomGame()));
    connect(exitButton,SIGNAL(clicked()),this,SIGNAL(toExit()));
    connect(registerButton,SIGNAL(clicked()),this,SIGNAL(toLogin()));

    addItem(titleText);
    addItem(playButton);
    addItem(randomButton);
    addItem(exitButton);
    addItem(registerButton);

}
