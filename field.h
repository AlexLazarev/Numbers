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

    int getSize() const;
    int getCountRow() const;
    bool isStalemate();

    QVector<int> getMask() const;

    void setMask(const QVector<int> &mask);
    void setCell(const int &x,const int &y,const int &cell );


    void addCell(int);
    void delRow(int);

    void init(QString mode);
private:
    QVector<int> cell;
};


