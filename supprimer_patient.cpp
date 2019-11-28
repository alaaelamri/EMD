#include "supprimer_patient.h"
#include "ui_supprimer_patient.h"
#include "modifier_patient.h"
Supprimer_Patient::Supprimer_Patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_Patient)
{
   ui->setupUi(this);
   ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
   QPixmap pix1("D:/Projet C++/Projet/Ressource/Background_color.png");
   int w1 = ui->label->width();
   int h1 = ui->label->height();
   ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));
   ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
   QPixmap pix2(":/Ressource/prescription.png");
   int w2 = ui->label_2->width();
   int h2 = ui->label_2->height();
   ui->label_2->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));
   QPixmap pix3(":/Ressource/job.png");
   int w3 = ui->label_3->width();
   int h3 = ui->label_3->height();
   ui->label_3->setPixmap(pix3.scaled(w3,h3,Qt::IgnoreAspectRatio));


}

Supprimer_Patient::~Supprimer_Patient()
{
    delete ui;
}

void Supprimer_Patient::openAfficher_Patient()
{
    mafficher_Patient = new Afficher_Patient();
    mafficher_Patient->show();
}

void Supprimer_Patient::openRecherche_Patient_2()
{
    mRecherche_Patient_2 = new Recherche_Patient_2();
    mRecherche_Patient_2->show();
}

void Supprimer_Patient::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");

}

void Supprimer_Patient::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    openAfficher_Patient();
}

void Supprimer_Patient::on_pushButton_pressed()
{

}

void Supprimer_Patient::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    openRecherche_Patient_2();
}
