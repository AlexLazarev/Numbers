#include "graphicsfield.h"
#include "defines.h"
#include "field.h"
#include <QDebug>

GraphicsField::GraphicsField(Images *p) : pictures(p)
{
    field = new Field();
    field->mixNumbers(32);
    gm = new GameManager(field);

}

QRectF GraphicsField::boundingRect() const{
    return QRectF(FIELD_X,FIELD_Y,FIELD_WIDTH,FIELD_HEIGHT);
}


void GraphicsField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawImage(0, 0, pictures->getImage("field"));
    painter->drawImage(FIELD_X, FIELD_Y, getFieldImage());

}

void GraphicsField::mousePressEvent(QGraphicsSceneMouseEvent *event){


    int x = event->scenePos().x(); // convert to int from float
    int y = event->scenePos().y();

    gm->step(QPoint(x,y));

    update();

}


QImage GraphicsField::getFieldImage(){
    int countRow = field->getCountRow();

    double cfx = FIELD_WIDTH / 10.0;
    double cfy = FIELD_HEIGHT / 10.0;

    QImage image( FIELD_WIDTH, countRow*cfy, QImage::Format_ARGB32 );
    int cell;
    image.fill( 0 );
    QPainter painter( &image );



    for( int j = 0; j < countRow; j++ )
        for( int i = 0; i < COUNT_COLUMN ; i++ ) {
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


