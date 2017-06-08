#pragma once
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class GameOverScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GameOverScene(QObject *parent = NULL);
    void init();
signals:
    void toGame();
    void toMenu();

private:
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *timeText;
};

