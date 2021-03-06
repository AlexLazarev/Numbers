#include "gamemanager.h"
#include <QDebug>
GameManager::GameManager(Field *f) : field(f){
}

void GameManager::clear(){
    isFirstSelected = false;
    isCrossed = false;
    AIactive = false;

    backMask.clear();
    backMask.push_front(field->getMask());

}


void GameManager::addCells(){
    QVector<int> newcell;
    int cell;

    for(int i = 0; i < field->getSize(); i++){
        cell = field->getCell(i);

        if(cell == 0)
            break;

        if(cell != -1)
            newcell.push_back(cell);
    }


    for(auto i: newcell)
        field->addCell(i);

    backMask.push_front(field->getMask());
}

bool GameManager::help(){


    AIactive = true;

    int firstCell, secondCell;

    for(int i = 0; i < field->getSize(); i++){
        firstCell = field->getCell(i);

        if(firstCell == -1)
            continue;

        //vertical search
        for(int j = i+1; j < field->getSize(); j++){

            secondCell = field->getCell(j);

            if(secondCell == -1)
                continue;

            if(firstCell == secondCell || (firstCell + secondCell) == 10){
                AIfirstIndex = convertToIndex(i);
                AIsecondIndex = convertToIndex(j);
                return true;
            }
            else
                break;

        }
        //horizontal search
        for(int j = i/COUNT_COLUMN+1; j < field->getCountRow(); j++){

            secondCell = field->getCell(j*COUNT_COLUMN + i%COUNT_COLUMN);

            if(secondCell == -1)
                continue;

            if(firstCell == secondCell || (firstCell + secondCell) == 10){
                AIfirstIndex = convertToIndex(i);
                AIsecondIndex = convertToIndex(j*COUNT_COLUMN + i%COUNT_COLUMN);
                return true;
            }
            else
                break;


        }
    }

    AIactive = false;

    return false;
}


void GameManager::backStep(){

    if(backMask.size() <= 1)
        return;


    backMask.pop_front(); // delete current stay

    field->setMask(*backMask.begin()); // set previous state
}






void GameManager::compressField(int row){
    int k = 0;
    for(int j = 0; j < COUNT_COLUMN; j++){
        if(field->getCell(row,j) == -1)
            k++;
        else
            break;

        if(k == COUNT_COLUMN){
            field->delRow(row);
        }
    }


}


void GameManager::step(QPoint coordCell){
    isCrossed = false;

    QPoint index = convertToIndex(coordCell);

    qDebug() << "Cell selected " << index.x() << index.y() << field->getCell(index.x(), index.y());

    if(!isFirstSelected)
        preindex = index; // select first cell
    else{
        if(checkCorrect(index))
            if(
                (field->getCell(index.x(),index.y()) == field->getCell(preindex.x(),preindex.y()) ||   // '2'+'2'
                 field->getCell(index.x(),index.y()) + field->getCell(preindex.x(),preindex.y()) == 10) && //'2'+'8" = '10'
                 field->getCell(index.x(),index.y()) != 0  // empty cells = 0

            ){
                //cells are crossed
                field->setCell(index.x(),index.y(), -1);
                field->setCell(preindex.x(),preindex.y(), -1);

                backMask.push_front(field->getMask());


                compressField(index.x());
                if(preindex.x() != index.x())
                    compressField(preindex.x());

                isCrossed = true;
                AIactive = false;
            }       
        }


    isFirstSelected = !isFirstSelected;
}




bool GameManager::checkCorrect(QPoint index){
   //vector position
   int n = index.x()*COUNT_COLUMN + index.y();
   int m = preindex.x() * COUNT_COLUMN + preindex.y();

   // check of click the same cell
   if( m == n)
       return false;


   //check of column
   if(index.y() == preindex.y()){
       if(m < n)
           for(int i = preindex.x()+1; i < index.x(); i++){
               if(field->getCell(i,index.y()) != -1)
                   return false;
           }
       else
           if(m > n)
               for(int i = index.x()+1; i < preindex.x(); i++){
                   if(field->getCell(i, index.y()) != -1)
                       return false;
               }
       return true;
   }


   //check of row
   if (m < n)
       for(int i = m+1; i < n; i++){
           if(field->getCell(i) != -1)
               return false;
       }
   else
      if(m > n)
          for(int i = n+1; i < m; i++){
              if(field->getCell(i) != -1)
                  return false;
          }


   return true;
}




QPoint GameManager::convertToIndex(const QPoint &pos){
    QPoint res(-1,-1);

    if(
        pos.x() < FIELD_X || pos.x() > (FIELD_X + FIELD_WIDTH) ||
        pos.y() < FIELD_Y
    )
        return res;

    res.setY( 1.0 * (pos.x() - FIELD_X) / CELL_WIDTH);
    res.setX( 1.0 * (pos.y() - FIELD_Y) / CELL_HEIGHT);

    return res;
}

QPoint GameManager::convertToIndex(int n){
    int x = n / COUNT_COLUMN;
    int y = n % COUNT_COLUMN;

    return QPoint(x,y);
}

QPoint GameManager::getSellectedIndex() const{
    if(isFirstSelected)
        return preindex;
    return QPoint(-1,-1);
}

bool GameManager::getIsCroosed() const{
    return isCrossed;
}

bool GameManager::getAIactive() const{
    return AIactive;
}

QPoint GameManager::getAIfirstIndex() const{
    return AIfirstIndex;
}

QPoint GameManager::getAIsecondIndex() const{
    return AIsecondIndex;
}
