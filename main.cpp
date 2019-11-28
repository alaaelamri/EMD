#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include "gestion_patient.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gestion_Patient g;
    MainWindow w;
    //w.show();
    g.show();
    Connection c;
    bool test=c.ouvrirConnexion();
  if(test)
  {
      //w.show();

      QMessageBox::information(nullptr, QObject::tr("database is open"),
                  QObject::tr("connection avec succés.\n"
                              "Click Ok to Continue."), QMessageBox::Ok);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
