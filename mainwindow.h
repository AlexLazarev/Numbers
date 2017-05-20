#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <Qpainter>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsScene>

#include "images.h"
#include "field.h"
#include "gamemanager.h"

namespace Ui {
class MainWindow;
}


class MainWindow :
        public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene getScene();

protected:
    void paintEvent( QPaintEvent* event );
    void mousePressEvent( QMouseEvent* ev );



private slots:
    void on_addButton_clicked();

private:
    QGraphicsScene *scene;

    QImage getFieldImage();
    Ui::MainWindow *ui;
    Images *pictures;
    Field *field;
    GameManager *gm;

};

#endif // MAINWINDOW_H
