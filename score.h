#pragma once

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem *parent = NULL);

    int getScore() const;

    void reset();
public slots:
    void increase(int);


private:
    int m_score;
};

