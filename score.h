#pragma once

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();


private:
    int scoreCount;
};

