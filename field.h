#pragma once
#include <QPoint>
#include <QVector>
#include "defines.h"


class Field
{
public:
    Field();
    ~Field();
    int getCell( int x, int y );
    int getCell(int n);
    void setCell( int x, int y, int cell );
    int getFieldSize();
    int getCountRow();


    void addCell(int);
    void clear();
    void delRow(int,int);

    void mixNumbers(int count);

private:
    QVector<int> cell;
};


