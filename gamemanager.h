#pragma once
#include <QPoint>
#include "field.h"

class GameManager
{
public:
    GameManager(Field*);

    void clear();


    void step(QPoint coordCell);

    void addCells();
    bool help();
    void backStep();

    bool getIsCroosed() const; //XM
    bool getAIactive() const;

    QPoint getAIfirstIndex() const;
    QPoint getAIsecondIndex() const;

    QPoint getSellectedIndex() const;


private:
    QPoint AIfirstIndex;
    QPoint AIsecondIndex;

    QVector<QVector<int>> backMask;

    QPoint convertToIndex(const QPoint& pos );
    QPoint convertToIndex(int n);

    bool checkCorrect(QPoint index);
    void compressField(int row);

    bool isFirstSelected;
    bool isCrossed;
    bool AIactive;



    Field *field;
    QPoint preindex;

};




