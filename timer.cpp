#include "timer.h"
#include <QTimer>
#include <QFont>
#include <QFontDatabase>
#include "defines.h"

Timer::Timer(QGraphicsItem *parent): QGraphicsTextItem(parent){
    timeCount = TIME_COUNT;

    setPlainText(QString::number(timeCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",16));
    startTimer(1000);

}

void Timer::timerEvent(QTimerEvent *){
    decrease();
}

void Timer::decrease(){

    if(0 != timeCount){
        timeCount--;
        setPlainText(QString::number(timeCount));
    }

}

int Timer::getTime() const{
    return timeCount;
}
