#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defines.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    pictures = new Images();
    pictures->load();


    field = new Field();

    field->clear();
    field->mixNumbers(15); // TODO: function into gm from field

    gm = new GameManager(field);

    this->update();
}

MainWindow::~MainWindow(){
    delete pictures;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    static const int deltaY = this->centralWidget()->y();

    QPainter painter(this);
    painter.drawImage(0, deltaY,pictures->getImage("field"));
    painter.drawImage( MYFIELD_X, MYFIELD_Y + deltaY, getFieldImage() );

}



QImage MainWindow::getFieldImage(){
    QImage image( FIELD_WIDTH, FIELD_HEIGHT, QImage::Format_ARGB32 );
    int cell;
    image.fill( 0 );
    QPainter painter( &image );

    double cfx = FIELD_WIDTH / 10.0;
    double cfy = FIELD_HEIGHT / 10.0;


    for( int i = 0; i < 10; i++ )
        for( int j = 0; j < 10; j++ ) {
            cell = field->getCell(i,j);

            switch( cell ) {

            case 1:
                painter.drawImage( i * cfx, j * cfy, pictures->getImage("one")); break;
            case 2:
                painter.drawImage( i * cfx, j * cfy, pictures->getImage("two")); break;
            case 3:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("three")); break;
            case 4:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("four")); break;
            case 5:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("five")); break;
            case 6:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("six")); break;
            case 7:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("seven")); break;
            case 8:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("eight")); break;
            case 9:
                 painter.drawImage( i * cfx, j * cfy, pictures->getImage("nine")); break;
            case -1:
                painter.drawImage( i * cfx, j * cfy, pictures->getImage("full")); break;
            default:             
                break;
            }
        }
    return image;
}



void MainWindow::mousePressEvent(QMouseEvent *ev){

    QPoint pos = ev->pos();
    pos.setY( pos.y() - this->centralWidget()->y());


    gm->check(pos);

    this->update();
}



