#include "gestion_patient.h"
#include "ui_gestion_patient.h"
#include <qpixmap.h>
#include <qlabel.h>
Gestion_Patient::Gestion_Patient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_Patient)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(click()), this, SLOT(open_Ajouter_Patient()));

    connect(ui->pushButton_2, SIGNAL(click()), this, SLOT(open_Modifier_Patient()));

    connect(ui->pushButton_3, SIGNAL(click()), this, SLOT(open_Supprimer_Patient()));

    QPixmap pix(":/Ressource/dashboard.jpg");
    int w = ui->label_Background->width();
    int h = ui->label_Background->height();
    ui->label_Background->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));

    QPixmap pix1(":Ressource/icon_add.png");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1,Qt::IgnoreAspectRatio));

    QPixmap pix2(":/Ressource/icon_edit.png");
    int w2 = ui->label_2->width();
    int h2 = ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(h2,w2,Qt::IgnoreAspectRatio));

    QPixmap pix3(":/Ressource/cancel.png");
    int w3 = ui->label_3->width();
    int h3 = ui->label_3->height();
    ui->label_3->setPixmap(pix3.scaled(h3,w3,Qt::IgnoreAspectRatio));

    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
}

Gestion_Patient::~Gestion_Patient()
{
    delete ui;
}

void Gestion_Patient::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
}

void Gestion_Patient::on_pushButton_released()
{
    ui->pushButton->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    open_Ajouter_Patient();
}

void Gestion_Patient::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
}

void Gestion_Patient::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    open_Modifier_Patient();
}


void Gestion_Patient::on_pushButton_3_pressed()
{
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_init.png)3 10 3 10; font: 24pt Bahnschrift;");
}


void Gestion_Patient::on_pushButton_3_released()
{
    ui->pushButton_3->setStyleSheet("border-image: url(D:/Projet C++/Projet/Ressource/button_clicked.png)3 10 3 10; font: 24pt Bahnschrift;");
    open_Supprimer_Patient();
}

void Gestion_Patient::open_Ajouter_Patient()
{
    mAjouterPatient = new Ajouter_Patient();
    mAjouterPatient->show();
}

void Gestion_Patient::open_Modifier_Patient()
{
    mModifierPatient = new Modifier_Patient();
    mModifierPatient->show();
}

void Gestion_Patient::open_Supprimer_Patient()
{
    mSupprimerPatient = new Supprimer_Patient();
    mSupprimerPatient->show();
}
