#pragma once
#include <QGraphicsScene>


class MenuScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MenuScene(QObject *parent = NULL);

signals:
    void toClassicGame();
    void toRandomGame();
    void toExit();
    void toLogin();
};

