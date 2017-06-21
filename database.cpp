#include "database.h"

namespace DataB{

bool regUsr(Query Input,QSqlDatabase db){

//Check user input against the database

    QSqlQuery Q(db);
    if(chkUsr(Input,db)){  
        QString insert="INSERT INTO BlogUser (username,password) VALUES(:first,:last)";

        Q.prepare(insert);
        Q.bindValue(":first",Input.uName);
        Q.bindValue(":last",Input.pass);

        Q.exec();
        db.close();
        return true;

    }
    else{
        db.close();
        return false;
    }
}


bool chkUsr(Query Input,QSqlDatabase db){
    QSqlQuery Q(db);

    QString select= "SELECT username FROM BlogUser WHERE username = :first";

    Q.prepare(select);
    Q.bindValue(":first", Input.uName);

    Q.exec();


    if(Q.first())
        return false;

    else
        return true;
}


bool DBConnect(Connection C){

    QString servername = "DESKTOP-8HCC0KB\\SQLEXP";
    QString dbname     = "Numbers";

    C.db    = QSqlDatabase::addDatabase("QODBC");

    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;").arg(servername).arg(dbname);

    C.db.setDatabaseName(dsn);

    if(!C.db.open()){
        C.connected = false;
        qDebug() << "Error = " << C.db.lastError().text();
        return C.connected;
    }

    qDebug() << "connected";
    C.connected = true;

    return C.connected;

    qDebug() << "Error = " << C.db.lastError().text();
}


bool cUsrPas(Query Input,QSqlDatabase db){
    QSqlQuery Q(db);

    QString select="SELECT username FROM BlogUser WHERE username = :first AND password = :last";

    Q.prepare(select);
    Q.bindValue(":first",Input.uName);
    Q.bindValue(":last",Input.pass);

    Q.exec();

    if(Q.first())
        return true;
    else
        return false;

}




}
