#pragma once
#include <QGraphicsTextItem>
#include <QTime>

class Timer: public QGraphicsTextItem{

public:
    Timer(QGraphicsItem *parent = NULL);

    QTime getTime() const;

    void timerEvent(QTimerEvent *);

    void reset();

private:
    void increase();
    QTime m_time;
};
