#pragma once
#include <QGraphicsTextItem>

class Timer: public QGraphicsTextItem{
public:
    Timer(QGraphicsItem * parent=0);
    void decrease();
    int getTime() const;
    void timerEvent(QTimerEvent *);

private:
    int timeCount;
};
