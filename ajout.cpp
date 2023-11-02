#include "ajout.h"
#include "employe.h"
#include "ui_ajout.h"
#include <QMessageBox>
#include <QRegExp>


ajout::ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout)
{
    ui->setupUi(this);
    id = ui->id;
    id->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    nom = ui->nom;
    nom->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    prenom = ui->prenom;
    prenom->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    date = ui->date;
    date->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    sexe = ui->sexe;
    sexe->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    ui->sexe->addItem("Homme");
    ui->sexe->addItem("Femme");
    email = ui->email;
    email->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    num = ui->num;
    num->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    poste = ui->poste;
    poste->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    date1 = ui->date1;
    date1->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    date2 = ui->date2;
    date2->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
}

ajout::~ajout()
{
    delete ui;
}

void ajout::on_eng_clicked()
{
        bool isIdValid = false;
        int id = ui->id->text().toInt(&isIdValid);
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        QString email=ui->email->text();
        QString numero_telephone=ui->num->text();
        QRegExp regex2("^[A-Za-z]{2,30}");
        QRegExp regex3("^[A-Za-z0-9]{3,30}$");
        QRegExp regex4("^[0-9]{8}$");

        if (isIdValid && QString::number(id).length() <= 4 /*&& nom.contains(regex2) && prenom.contains(regex2) && email.contains(regex3) && email.contains("@",Qt::CaseInsensitive) && numero_telephone.contains(regex4)*/)
        {
        QDate date_naissance=ui->date->date();
        QString poste=ui->poste->text();
        QString sexe=ui->sexe->currentText();
        QDate date_embauche=ui->date1->date();
        QDate fin_contrat=ui->date2->date();
        Employe E(id,nom,prenom,date_naissance,poste,sexe,email,numero_telephone,date_embauche,fin_contrat);
        bool test=E.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("Ajout effectué\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("Ajout non effectué\nClick Cancel to exit."),QMessageBox::Cancel);
        }

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("id ghalet\nClick Cancel to exit."),QMessageBox::Cancel);

        }
}


void ajout::on_modifier_clicked()
{
        Employe e;
        e.setid(ui->id->text().toInt());
        e.setnom(ui->nom->text());
        e.setprenom(ui->prenom->text());
        e.setdate_naissance(ui->date->date());
        e.setemail(ui->email->text());
        e.setsexe(ui->sexe->currentText());
        e.setnumero_telephone(ui->num->text());
        e.setdate_embauche(ui->date1->date());
        e.setfin_contrat(ui->date2->date());
        e.setposte(ui->poste->text());

        bool test=e.modifier(e.getid());
        if(test)
        {
            QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("modification effectué\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("modification non effectué\nClick Cancel to exit."), QMessageBox::Cancel);
        }
}
