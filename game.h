#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>


#include "images.h"


class Game : public QGraphicsView
{
    Q_OBJECT


public:
    Game(QWidget * parent = NULL);
    ~Game();

public slots:
    void showMenu();

    void showGame();

private:

    QGraphicsScene *scene;
    Images *pictures;
};

