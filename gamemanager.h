#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <QPoint>
#include "field.h"

class GameManager
{
public:
    GameManager(Field*);
    void step(QPoint coordCell);
    void addCells();
private:
    void updateWorkCell();
    QPoint convertToIndex(const QPoint& pos );
    bool checkCorrect(QPoint index);
    bool isFirstSelected;
    Field *field;
    QPoint preindex;
    QVector<int> workcell;
};

#endif // GAMEMANAGER_H
