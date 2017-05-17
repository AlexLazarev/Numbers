#include "Field.h"
#include <QDebug>
#include <time.h>
Field::Field(){
    clear();
}



void Field::mixNumbers(int count){

    srand(time(0));
    for(int i = 0; i < count; i++)
        cell[i] = rand()%10;

}

void Field::delRow(int x, int y){
    int n = y * 10 + x;
    //TODO::Realize delete row
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

    if(x >= 0 && y >= 0 && x < 10 && y < 10)
        cell[n] = num;
}

void Field::clear(){
    cell.fill( 0, 100 );
}








