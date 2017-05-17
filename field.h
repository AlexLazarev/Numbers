#pragma once
#include "images.h"
#include <QPoint>
#include "defines.h"


class Field
{
public:
    Field();
    ~Field();
    int getCell( int x, int y );
    int getCell(int n);
    void setCell( int x, int y, int cell );
    void clear();
    void delRow(int,int);

    void mixNumbers(int count);

private:
    QVector<int> cell;
};

//TODO: convertToIndex -> external function

