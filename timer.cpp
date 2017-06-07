#include "timer.h"
#include <QTimer>
#include <QFont>
#include <QFontDatabase>
#include "defines.h"

Timer::Timer(QGraphicsItem *parent): isPause(false), timeCount(TIME_COUNT), QGraphicsTextItem(parent){

    setPlainText(QString::number(timeCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));
    startTimer(1000);

}

void Timer::timerEvent(QTimerEvent *){
    if(!isPause)
        decrease();
}

void Timer::pause(){
    isPause = true;
}

void Timer::decrease(){
    if(timeCount != 0){
        timeCount--;
        setPlainText(QString::number(timeCount));
    }

}

int Timer::getTime() const{
    return timeCount;
}
