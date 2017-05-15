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
    void setCell( int x, int y, int cell );
    void clear();
    QPoint convertToIndex(const QPoint& pos );

    void mixNumbers(int count);

private:
    QVector<int> cell;
};

//TODO: convertToIndex -> external function

