#pragma once
#include <QGraphicsScene>


class GameOverScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameOverScene(QObject *parent = NULL);

signals:
    void toReplay();
    void toExit();

};

