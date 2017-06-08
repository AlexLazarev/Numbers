#include "gameoverscene.h"


#include "defines.h"
#include "button.h"
#include "images.h"
#include "storage.h"

GameOverScene::GameOverScene(QObject *parent):QGraphicsScene(parent){

    setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);


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

    Button *replayButton = new Button(QString("REPLAY"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    Button *menuButton = new Button(QString("MENU"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);



    int centre = this->width()/2;

    titleText->setPos(centre - titleText->boundingRect().width()/2, 160);
    scoreText->setPos(centre * 0.45, 250);
    timeText->setPos(centre * 0.45, 270);

    replayButton->setPos(centre * 0.45, 300);
    menuButton->setPos(centre * 1.05, 300);


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
    timeText->setPlainText(QString("Time  : ") + QString::number(Storage::getInstance()->getTime()));

}
