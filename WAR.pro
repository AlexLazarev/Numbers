#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T00:17:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WAR
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    field.cpp \
    images.cpp \
    gamemanager.cpp \
    button.cpp \
    game.cpp \
    score.cpp \
    timer.cpp \
    fieldItem.cpp \
    gamescene.cpp \
    panel.cpp \
    menuscene.cpp \
    gameoverscene.cpp \
    storage.cpp \
    database.cpp \
    loginwindow.cpp

HEADERS  += \
    field.h \
    images.h \
    defines.h \
    gamemanager.h \
    button.h \
    game.h \
    score.h \
    timer.h \
    fieldItem.h \
    gamescene.h \
    panel.h \
    menuscene.h \
    gameoverscene.h \
    storage.h \
    database.h \
    loginwindow.h

RESOURCES += \
    resourse.qrc

FORMS += \
    loginwindow.ui
