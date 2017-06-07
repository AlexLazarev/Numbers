#pragma once

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem *parent = NULL);

    int getScore() const;

public slots:
    void increase(int);


private:
    int scoreCount;
};

