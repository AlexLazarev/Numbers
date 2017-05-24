#include "Field.h"
#include <QDebug>
#include <time.h>
Field::Field(){
    clear();
}



void Field::mixNumbers(int amt){
    srand(time(0));

    for(int i = 0; i < amt; i++)
        cell.push_back(rand()%9+1);

}

void Field::delRow(int x, int y){
    int n = y * 10 + x;
    n += n;
    //TODO::Realize delete row
}

void Field::addCell(int c){
    cell.push_back(c);
    qDebug() << cell.size();
}



int Field::getCell( int x, int y ){
    int n = y * 10 + x;

    if( n >= 0 && n < cell.size() )
        return cell[n];

    return 0;
}

int Field::getCell(int n){
    if( n >= 0 && n < cell.size() )
        return cell[n];

    return 0;
}

void Field::setCell(int x, int y, int num ){
    int n = y * 10 + x;

    if(x >= 0 && y >= 0 && x < COUNT_COLUMN)
        cell[n] = num;
}

int Field::getFieldSize(){
    return cell.size();
}

int Field::getCountRow(){
    if(cell.size() % COUNT_COLUMN == 0)
        return cell.size()/COUNT_COLUMN;

    return cell.size()/COUNT_COLUMN+1;
}

void Field::clear(){

}









