#pragma once
#include <QPoint>
#include <QVector>
#include "defines.h"


class Field
{
public:
    Field();
    ~Field();
    int getCell( int x, int y ) const;
    int getCell(int n) const;
    void setCell( int x, int y, int cell );
    int getSize() const;
    int getCountRow() const;

    QVector<int> getMask() const;

    void setMask(const QVector<int> &mask);

    void addCell(int);

    void delRow(int);

    void mixNumbers(int count);

private:
    QVector<int> cell;
};


