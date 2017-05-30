#pragma once

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem *parent=0);

    int getScore() const;

public slots:
    void increase(int);


private:
    int scoreCount;
};

