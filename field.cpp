#include "Field.h"
#include <QDebug>

Field::Field(){
}

Field::~Field(){

}


void Field::init(QString mode){
    cell.clear();

    if(mode == "CLASSIC")
        for(int i = 0; i < COUNT_CELL; i++)
            cell.push_back(CLASSIC_CELLS[i]);

    else
        if(mode == "RANDOM")
        for(int i = 0; i < COUNT_CELL; i++)
            cell.push_back(rand()%9+1);

}

void Field::delRow(int indexRow){

    cell.erase(cell.begin() + (indexRow*COUNT_COLUMN),
         cell.begin() + (indexRow*COUNT_COLUMN+COUNT_COLUMN));
    if(cell.size() < COUNT_COLUMN){
        for(int i = 0; i < cell.size(); i++)
            if(cell[i] != -1)
                return;
        cell.clear();
    }

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

void Field::setCell(const int &x,const int &y,const int &num){
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

bool Field::isStalemate(){
    return false;
}

QVector<int> Field::getMask() const{
    return cell;
}

void Field::setMask(const QVector<int> &mask){
    cell = mask;
}









