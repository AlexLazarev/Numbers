#include "gamemanager.h"
#include <QDebug>
GameManager::GameManager(Field *f) : field(f), isFirstSelected(false)
{
}


//TODO: add sum 10, add check of click the same cell
void GameManager::check(QPoint newCell){
    QPoint index = convertToIndex(newCell);
    qDebug() << "Cell selected " << index.x() << index.y();
    if(!isFirstSelected)
        preindex = index;
    else
        if(field->getCell(index.x(),index.y()) == field->getCell(preindex.x(),preindex.y())){
            field->setCell(index.x(),index.y(), -1);
            field->setCell(preindex.x(),preindex.y(), -1);
        }

    isFirstSelected = !isFirstSelected;
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
