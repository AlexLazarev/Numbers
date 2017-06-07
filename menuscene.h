#pragma once
#include <QGraphicsScene>


class MenuScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MenuScene(QObject *parent = NULL);

signals:
    void toGame();
    void toExit();

};

