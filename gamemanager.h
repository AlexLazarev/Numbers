#pragma once
#include <QPoint>
#include "field.h"

class GameManager
{
public:
    GameManager(Field*);
    void step(QPoint coordCell);

    void delRow();
    void addCells();
    bool getIsCroosed(); //XM


    QPoint getSellectedIndex() const;

private:

    QPoint convertToIndex(const QPoint& pos );

    bool checkCorrect(QPoint index);
    bool isFirstSelected;
    bool isCrossed;

    Field *field;
    QPoint preindex;
};




