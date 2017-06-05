#pragma once

#include <QMap>
#include <QImage>
#include <QString>

class Images
{
public:
    Images();

    void load();
    QImage &getImage(const QString& imgName);

    static Images *getInstance();


private:
    QMap<QString,QImage> images;
    bool isLoaded;

};

