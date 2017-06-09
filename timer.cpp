#include "timer.h"
#include <QTimer>
#include <QFont>
#include <QFontDatabase>
#include "defines.h"

Timer::Timer(QGraphicsItem *parent): QGraphicsTextItem(parent){


    reset();

    setPlainText(m_time.toString("hh:mm:ss"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));
    startTimer(1000);



}

void Timer::timerEvent(QTimerEvent *){
    increase();

}

void Timer::reset(){
    m_time.setHMS(0,0,0);

}

void Timer::increase(){
    m_time = m_time.addSecs(1);
    setPlainText(m_time.toString("hh:mm:ss"));
}

QTime Timer::getTime() const{
    return m_time;
}
