#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QMouseEvent>


#include "images.h"


class SceneManager : public QGraphicsView
{
    Q_OBJECT


public:
    SceneManager(QWidget * parent = NULL);
    ~SceneManager();

public slots:
    void showMenu();

    void showGame();

private:

    QGraphicsScene *scene;
    Images *pictures;
};

