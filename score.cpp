#include "score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the coinCount to 0
    scoreCount = 0;

    setPlainText(QString("Score ") + QString::number(scoreCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",30));


}

void Score::increase(){
    scoreCount += 10;
    setPlainText(QString("Score ") + QString::number(scoreCount * 15));

}

int Score::getScore(){
    return scoreCount;
}
