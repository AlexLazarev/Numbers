#include "Field.h"
#include <QDebug>
#include <time.h>
Field::Field(){
}

Field::~Field(){

}



void Field::mixNumbers(int amt){
    srand(time(0));

    for(int i = 0; i < amt; i++)
        cell.push_back(rand()%9 +1);


}

void Field::delRow(int indexRow){
    cell.erase(cell.begin() + (indexRow*COUNT_COLUMN),
               cell.begin() + (indexRow*COUNT_COLUMN+COUNT_COLUMN));
}

void Field::addCell(int c){
    cell.push_back(c);
    qDebug() << cell.size();
}



int Field::getCell( int x, int y ) const {
    int n = x * COUNT_COLUMN + y;

    if( n >= 0 && n < cell.size() )
        return cell[n];

    return 0;
}

int Field::getCell(int n) const {
    if( n >= 0 && n < cell.size() )
        return cell[n];

    return 0;
}

void Field::setCell(int x, int y, int num ){
    int n = x * COUNT_COLUMN + y;


    if(x >= 0 && y >= 0 && y < COUNT_COLUMN)
        cell[n] = num;
}

int Field::getSize() const {
    return cell.size();
}

int Field::getCountRow() const {


    if(cell.size() % COUNT_COLUMN == 0)
        return cell.size()/COUNT_COLUMN;

    return cell.size()/COUNT_COLUMN+1;
}

QVector<int> Field::getMask() const{
    return cell;
}

void Field::setMask(const QVector<int> &mask){


    cell = mask;
}









