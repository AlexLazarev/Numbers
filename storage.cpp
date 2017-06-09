#include "storage.h"



Storage::Storage()
{

}

Storage *Storage::getInstance(){
    static Storage instance;
    return &instance;
}

void Storage::setScore(const int &score){
    m_score = score;
}

void Storage::setTime(const QTime &time){
    m_time = time;
}


void Storage::setField(const QVector<int> &field){
    m_field = field;
}

void Storage::setMode(const QString &mode){
    m_mode = mode;
}

QString Storage::getMode() const{
    return m_mode;
}

QTime Storage::getTime() const{
    return m_time;
}

int Storage::getScore() const{
    return m_score;
}

QVector<int> Storage::getField() const{
    return m_field;
}
