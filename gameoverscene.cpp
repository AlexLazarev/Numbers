#include "gameoverscene.h"


#include "defines.h"
#include "button.h"
#include "images.h"
#include "storage.h"

GameOverScene::GameOverScene(QObject *parent):QGraphicsScene(parent){

    setSceneRect(0,0,WINDOW_WIDTH-3,WINDOW_HEIGHT-3);


    QBrush brush;
    brush.setTextureImage( Images::getInstance()->getImage("background"));

    setBackgroundBrush(brush);





    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("GAME OVER"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);

    scoreText = new QGraphicsTextItem();
    timeText = new QGraphicsTextItem();

    QFont font("Helvetica", 15);
    scoreText->setFont(font);
    timeText->setFont(font);

    Button *replayButton = new Button(QString("REPLAY"), MENU_BUTTON_WIDTH/1.5, MENU_BUTTON_HEIGHT/1.5);
    Button *menuButton = new Button(QString("MENU"), MENU_BUTTON_WIDTH/1.5, MENU_BUTTON_HEIGHT/1.5);



    int centre = this->width()/2;

    titleText->setPos(centre - titleText->boundingRect().width()/2, 160);
    scoreText->setPos(centre * 0.45, 250);
    timeText->setPos(centre * 0.45, 270);

    replayButton->setPos(centre * 0.55, 330);
    menuButton->setPos(centre * 1.15, 330);


    connect(replayButton,SIGNAL(clicked()),this,SIGNAL(toGame()));
    connect(menuButton,SIGNAL(clicked()),this,SIGNAL(toMenu()));


    addItem(titleText);
    addItem(scoreText);
    addItem(timeText);

    addItem(replayButton);
    addItem(menuButton);

}

void GameOverScene::init(){
    scoreText->setPlainText(QString("Score : ") + QString::number(Storage::getInstance()->getScore()));
    timeText->setPlainText(QString("Time  : ") + (Storage::getInstance()->getTime()).toString("hh:mm:ss"));

}
