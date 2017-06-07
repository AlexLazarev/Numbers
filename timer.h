#pragma once
#include <QGraphicsTextItem>

class Timer: public QGraphicsTextItem{
    Q_OBJECT
public:
    Timer(QGraphicsItem *parent = NULL);
    void decrease();
    int getTime() const;
    void timerEvent(QTimerEvent *);

public slots:
    void pause();


private:
    bool isPause;
    int timeCount;
};
