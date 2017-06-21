#pragma once

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

//Structures
struct Connection{
    QSqlDatabase db;
    bool connected;
};
//SQL Query
struct Query{
    QString uName;
    QString pass;
};

namespace DataB{

bool regUsr(Query,QSqlDatabase);
//Checks to see if the username is taken
bool chkUsr(Query,QSqlDatabase);
//Checks to see if a Username and password Match in database
bool cUsrPas(Query,QSqlDatabase);
//Connects to Database
bool DBConnect(Connection);

}
