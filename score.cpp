#include "score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the coinCount to 0
    scoreCount = 0;

    setPlainText(QString("Score: ") + QString::number(scoreCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",20));


}

void Score::increase(int score){
    scoreCount += score;
    setPlainText(QString("Score ") + QString::number(scoreCount));

}

int Score::getScore() const{
    return scoreCount;
}
