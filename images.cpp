#include "images.h"

Images::Images(){
    isLoaded = false;
}


void Images::load(){

    if(isLoaded)
        return;

   images.insert("field",QImage(":/images/background.png"));
   images.insert("one",QImage(":/images/one.png"));
   images.insert("two",QImage(":/images/two.png"));
   images.insert("three",QImage(":/images/three.png"));
   images.insert("four",QImage(":/images/four.png"));
   images.insert("five",QImage(":/images/five.png"));
   images.insert("six",QImage(":/images/six.png"));
   images.insert("seven",QImage(":/images/seven.png"));
   images.insert("eight",QImage(":/images/eight.png"));
   images.insert("nine",QImage(":/images/nine.png"));


   images.insert("full",QImage(":/images/full.png"));

   isLoaded = true;
}
QImage& Images::getImage(const QString &imgName){
    QMap<QString,QImage>::iterator i = images.find(imgName);

    if(i == images.end())
        throw 1;

    return i.value();
}
