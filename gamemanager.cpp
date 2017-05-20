#include "gamemanager.h"
#include <QDebug>
GameManager::GameManager(Field *f) : field(f), isFirstSelected(false)
{
}

//TODO: checkCorrect with workCell
void GameManager::addCells(){
    updateWorkCell();

    for(auto i: workcell)
        field->addCell(i);
}

void GameManager::updateWorkCell(){
    int cell;

    for(int i = 0; i < field->getFieldSize(); i++){
        cell = field->getCell(i);

        if(cell == 0)
            break;

        if(cell != -1)
            workcell.push_back(cell);
    }

    qDebug() << workcell.length();
}



void GameManager::step(QPoint coordCell){
    QPoint index = convertToIndex(coordCell);

    qDebug() << "Cell selected " << index.x() << index.y();

    if(!isFirstSelected)
        preindex = index;
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
            }
        }
    isFirstSelected = !isFirstSelected;
}


bool GameManager::checkCorrect(QPoint index){
   //vector position
   int n = index.y()*10+index.x();
   int m = preindex.y() * 10 + preindex.x();

   // check of click the same cell
   if( m == n)
       return false;


   //check of column
   if(index.x() == preindex.x()){  // maybe I mixed up 'x' and 'y'
       if(m < n)
           for(int i = preindex.y()+1; i < index.y(); i++ ){
               if(field->getCell(index.x(),i) != -1)
                   return false;
           }
       else
           if(m > n)
               for(int i = index.y()+1; i < preindex.y(); i++ ){
                   if(field->getCell(index.x(),i) != -1)
                       return false;
               }
       return true;
   }


   //check of row
   if (m < n)
       for(int i = m+1; i < n; i++ ){
           if(field->getCell(i) != -1)
               return false;
       }
   else
      if(m > n)
          for(int i = n+1; i < m; i++ ){
              if(field->getCell(i) != -1)
                  return false;
          }


   return true;


}



QPoint GameManager::convertToIndex(const QPoint &pos){
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
