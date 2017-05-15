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




int Field::getCell( int x, int y ){
    int n = y * 10 + x;

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





QPoint Field::convertToIndex( const QPoint& pos ){
    QPoint res(-1,-1);

    if(
        pos.x() < MYFIELD_X || pos.x() > (MYFIELD_X + FIELD_WIDTH) ||
        pos.y() < MYFIELD_Y || pos.y() > (MYFIELD_Y + FIELD_HEIGHT)
    )
        return res;

    res.setX( 1.0 * (pos.x() - MYFIELD_X) / (0.1 * FIELD_WIDTH) );
    res.setY( 1.0 * (pos.y() - MYFIELD_Y) / (0.1 * FIELD_HEIGHT) );


    return res;
}


