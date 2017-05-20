#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>


class SceneManager
{
public:
    SceneManager();
    void showMenu();
    void showSplash();
    void showGame();

private:
    QGraphicsView *view;

};

