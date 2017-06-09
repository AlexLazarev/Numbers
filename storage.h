#include <QVector>
#include <QTime>

class Storage
{
public:
     static Storage *getInstance();

     void setScore(const int &score);
     void setTime(const QTime &time);
     void setField(const QVector<int> &field);
     void setMode(const QString &mode);

     QString getMode() const;
     int getScore() const;
     QTime getTime() const;
     QVector<int> getField() const;

private:
    QString m_mode;
    int m_score;
    QTime m_time;
    QVector<int> m_field;

    Storage();
};
