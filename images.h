#pragma once

#include <QMap>
#include <QImage>
#include <QString>

class Images
{
public:

    void load();
    QImage &getImage(const QString& imgName);

    static Images *getInstance();

private:
    Images();
    QMap<QString,QImage> images;
    bool isLoaded;

};

