#include "afficher_patient.h"
#include "ui_afficher_patient.h"
#include "patient.h"
#include "QSqlQuery"
#include "QMessageBox"
Afficher_Patient::Afficher_Patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher_Patient)
{
    ui->setupUi(this);
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TABLE_PATIENT");
    model->setHeaderData(0, Qt::Vertical, tr("Nom "));
    model->setHeaderData(1, Qt::Vertical, tr("Prénom"));
    model->setHeaderData(2, Qt::Vertical, tr("Date"));
    model->setHeaderData(3, Qt::Vertical, tr("Lieu"));
    model->setHeaderData(4, Qt::Vertical, tr("CIN"));
    model->setHeaderData(5, Qt::Vertical, tr("Adresse"));
    model->setHeaderData(6, Qt::Vertical, tr("Sexe"));
    ui->tableView->setModel(model);
    ui->tableView->setCurrentIndex(model->index(0,0));
    ui->tableView->viewport();
    QPixmap pix("D:/Projet C++/Projet/Ressource/Background_color.png");
    int w = ui->label_background->width();
    int h = ui->label_background->height();
    ui->label_background->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
    QPixmap pix1("D:/Projet C++/Projet/Ressource/job.png");
    int w1 = ui->label_Recherche->width();
    int h1 = ui->label_Recherche->height();
    ui->label_Recherche->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));
    ui->Button_R_A->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
}

Afficher_Patient::~Afficher_Patient()
{
    delete ui;
}

void Afficher_Patient::on_Button_R_A_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM TABLE_PATIENT ORDER BY NOM DESC");
    if (query.exec())
    {
        QMessageBox::information(this, tr("TRI"), tr("Le tableau a été trié avec succes!"));
    }
}
