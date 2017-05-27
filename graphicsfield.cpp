#include "graphicsfield.h"
#include "defines.h"
#include "field.h"
#include <QDebug>

GraphicsField::GraphicsField(Images *p) : pictures(p)
{
    field = new Field();
    field->mixNumbers(10);
    gm = new GameManager(field);

}

QRectF GraphicsField::boundingRect() const{
    return QRectF(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
}


void GraphicsField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(0, 0, pictures->getImage("field"));
    painter->drawImage(FIELD_X, FIELD_Y, getFieldImage());

}

void GraphicsField::mousePressEvent(QGraphicsSceneMouseEvent *event){


    int x = event->scenePos().x(); // convert to int from float
    int y = event->scenePos().y();

    gm->step(QPoint(x,y));

    update();

}

void GraphicsField::addCells(){
    gm->addCells();

    update();
}

void GraphicsField::delRow()
{
    gm->delRow();

    update();
}



QImage GraphicsField::getFieldImage(){
    int countRow = field->getCountRow();

    // DEBUG
    static int i = 0;
    i++;
    qDebug() << "DRAW" << i;
    //

    double cwh = FIELD_WIDTH / COUNT_COLUMN; // cell width and height

    QImage image( FIELD_WIDTH, countRow*cwh, QImage::Format_ARGB32 );

    int cell;
    image.fill( 0 );
    QPainter painter(&image);



    for( int i = 0; i < countRow; i++ )
        for( int j = 0; j < COUNT_COLUMN; j++ ) {
            cell = field->getCell(i,j);



            switch( cell ) {

            case 1:
                painter.drawImage( j * cwh, i * cwh, pictures->getImage("one")); break;
            case 2:
                painter.drawImage( j * cwh, i * cwh, pictures->getImage("two")); break;
            case 3:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("three")); break;
            case 4:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("four")); break;
            case 5:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("five")); break;
            case 6:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("six")); break;
            case 7:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("seven")); break;
            case 8:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("eight")); break;
            case 9:
                 painter.drawImage( j * cwh, i * cwh, pictures->getImage("nine")); break;
            case -1:
                painter.drawImage( j * cwh, i * cwh, pictures->getImage("full")); break;
            default:
                break;

            }

        }

    if(gm->getSellectedIndex() != QPoint(-1,-1)){
        painter.setPen(QPen(Qt::red,2));
        painter.drawRect(gm->getSellectedIndex().y() * cwh,
                         gm->getSellectedIndex().x() * cwh,
                         CELL_WIDTH,
                         CELL_HEIGHT);
    }
    return image;
}


