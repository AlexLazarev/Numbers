#include "score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    reset();

    setPlainText(QString("Score: ") + QString::number(m_score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));

}

void Score::increase(int score){
    m_score += score;
    setPlainText(QString("Score ") + QString::number(m_score));

}

int Score::getScore() const{
    return m_score;
}

void Score::reset(){
    m_score = 0;
    setPlainText(QString("Score ") + QString::number(m_score));
}
