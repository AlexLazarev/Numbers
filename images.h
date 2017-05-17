#ifndef IMAGES_H
#define IMAGES_H

#include <QMap>
#include <QImage>
#include <QString>

class Images
{
public:
    Images();

    void load();
    QImage &getImage(const QString& imgName);
private:
    QMap<QString,QImage> images;
    bool isLoaded;

};

#endif // IMAGES_H