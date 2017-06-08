#include "timer.h"
#include <QTimer>
#include <QFont>
#include <QFontDatabase>
#include "defines.h"

Timer::Timer(QGraphicsItem *parent): isPause(false), QGraphicsTextItem(parent){


    reset();

    setPlainText(QString::number(m_time));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));
    startTimer(1000);

}

void Timer::timerEvent(QTimerEvent *){
        increase();
}

void Timer::reset(){
    m_time = 0;
    setPlainText(QString::number(m_time));
}

void Timer::pause(){
    isPause = true;
}

void Timer::increase(){
    m_time++;
    setPlainText(QString::number(m_time));
}

int Timer::getTime() const{
    return m_time;

}
