#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inspection.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_inspection->setModel(I.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    Inspection I(id,nom,prenom);
    bool test=I.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout successful.\n""Click cancel to exit."),QMessageBox::Cancel);
       // ui->tab_etudiant->setModel(I.afficher());
        ui->tab_inspection->setModel(I.afficher());
    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout failed.\n""Click cancel to exit."),QMessageBox::Cancel);
       }

}

void MainWindow::on_bt_supprimer_clicked()
{
    Inspection i1;
    i1.setid(ui->le_id_supp->text().toInt());\
    bool test=i1.supprimer(i1.getid());
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression successful.\n""Click cancel to exit."),QMessageBox::Cancel);
       // ui->tab_etudiant->setModel(I.afficher());
        ui->tab_inspection->setModel(I.afficher());
    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout suppression.\n""Click cancel to exit."),QMessageBox::Cancel);
       }
}
