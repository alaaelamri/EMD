#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
namespace Ui {
class Modifier;
}

class Modifier : public QDialog
{
    Q_OBJECT
public slots:
    void on_radioMale_clicked();
    void on_radioFemelle_clicked();
    void open_Gestion_patient();
public:
    explicit Modifier(QWidget *parent, QString);
    ~Modifier();

private slots:
    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_clicked();

private:
    Ui::Modifier *ui;
};

#endif // MODIFIER_H
