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
    void help();


    bool getIsCroosed(); //XM
    bool getAIactive();

    QPoint getAIfirstIndex() const;
    QPoint getAIsecondIndex() const;

    QPoint getSellectedIndex() const;


private:
    QPoint AIfirstIndex;
    QPoint AIsecondIndex;


    QPoint convertToIndex(const QPoint& pos );
    QPoint convertToIndex(int n);

    bool checkCorrect(QPoint index);

    bool isFirstSelected;
    bool isCrossed;
    bool AIactive;



    Field *field;
    QPoint preindex;

};




