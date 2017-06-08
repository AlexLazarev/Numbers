#pragma once
#include <QGraphicsTextItem>

class Timer: public QGraphicsTextItem{
    Q_OBJECT
public:
    Timer(QGraphicsItem *parent = NULL);

    int getTime() const;
    void timerEvent(QTimerEvent *);

    void reset();
public slots:
    void pause();


private:
    void increase();

    bool isPause;
    int m_time;
};
