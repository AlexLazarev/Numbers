#include "images.h"

Images::Images(){
    isLoaded = false;
}


void Images::load(){

    if(isLoaded)
        return;

   images.insert("one",QImage(":/images/img/one.png"));
   images.insert("two",QImage(":/images/img/two.png"));
   images.insert("three",QImage(":/images/img/three.png"));
   images.insert("four",QImage(":/images/img/four.png"));
   images.insert("five",QImage(":/images/img/five.png"));
   images.insert("six",QImage(":/images/img/six.png"));
   images.insert("seven",QImage(":/images/img/seven.png"));
   images.insert("eight",QImage(":/images/img/eight.png"));
   images.insert("nine",QImage(":/images/img/nine.png"));

   images.insert("panel",QImage(":/images/img/panel.png"));
   images.insert("timer",QImage(":/images/img/timer.png"));
   images.insert("background",QImage(":/images/img/backgroundP.jpg"));

   images.insert("crossed",QImage(":/images/img/crossed.png"));


   isLoaded = true;
}
QImage& Images::getImage(const QString &imgName){
    QMap<QString,QImage>::iterator i = images.find(imgName);

    if(i == images.end())
        throw 1;

    return i.value();
}

Images *Images::getInstance(){
    static Images instance;
    return &instance;
}
