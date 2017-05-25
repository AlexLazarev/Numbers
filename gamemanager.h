#pragma once
#include <QPoint>
#include "field.h"

class GameManager
{
public:
    GameManager(Field*);
    void step(QPoint coordCell);

    void addCells();
private:
    void selectCell();
    void updateWorkCell();
    QPoint convertToIndex(const QPoint& pos );

    bool checkCorrect(QPoint index);
    bool isFirstSelected;

    Field *field;

    QPoint preindex;
    QVector<int> newcell;
};


