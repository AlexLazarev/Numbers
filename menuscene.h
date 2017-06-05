#pragma once
#include <QGraphicsScene>


class MenuScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MenuScene(QObject *parent = 0);

signals:
    void toGame();
    void toExit();

};

