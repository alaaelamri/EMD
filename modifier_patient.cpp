#include "modifier_patient.h"
#include "ui_modifier_patient.h"
#include "recherche_patient.h"
Modifier_Patient::Modifier_Patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier_Patient)
{
    ui->setupUi(this);
    QPixmap pix1("D:/Projet C++/Projet/Ressource/Background_color.png");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pix(":/Ressource/job.png");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/prescription.png");
    int w2 = ui->label_3->width();
    int h2 = ui->label_3->height();
    ui->label_3->setPixmap(pix2.scaled(w2,h2,Qt::IgnoreAspectRatio));

    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");

    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");

    connect(ui->pushButton, SIGNAL(click()), this, SLOT(openRecherche_Patient()));

}

Modifier_Patient::~Modifier_Patient()
{
    delete ui;
}

void Modifier_Patient::openRecherche_Patient()
{
    mrecherche_Patient = new Recherche_Patient();

    mrecherche_Patient->show();
}

void Modifier_Patient::on_pushButton_clicked()
{
    ui->pushButton->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    openRecherche_Patient();

}

void Modifier_Patient::on_pushButton_2_clicked()
{
    ui->pushButton_2->setStyleSheet("border-image: url(:/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    openAfficher_Patient();

}
void Modifier_Patient::openAfficher_Patient()
{
    mafficher_Patient = new Afficher_Patient();
    mafficher_Patient->show();
}
