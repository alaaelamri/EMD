#include "connection.h"
#include <QSqlError>

Connection::Connection(){
                      }
bool Connection::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("alaa");
                           db.setUserName("SYSTEM");//inserer nom de l'utilisateur
                           db.setPassword("alaa2011");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connection::fermerConnexion()
{
    db.close();
}
