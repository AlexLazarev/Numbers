#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <QPoint>
#include "field.h"

class GameManager
{
public:
    GameManager(Field*);
    void check(QPoint);

private:
    QPoint convertToIndex(const QPoint& pos );
    bool isFirstSelected;
    Field *field;
    QPoint preindex;
};

#endif // GAMEMANAGER_H
