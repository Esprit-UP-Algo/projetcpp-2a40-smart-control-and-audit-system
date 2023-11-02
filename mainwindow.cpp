#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "formation.h"
#include "connexion.h"
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->IDFOR->setValidator(new QIntValidator(100,9999,this));
    ui->tableView->setModel(f.afficher());

    ui->gestion_formation->show();
    ui->ajouter_formation->hide();
    // x
    ui->IDFOR->setClearButtonEnabled(true);
      ui->formateur->setClearButtonEnabled(true);
      ui->duree->setClearButtonEnabled(true);
        ui->nb_place->setClearButtonEnabled(true);

        //size
        setFixedSize(1920,1080);

//stylesheet lineEdit
        /*ui->tableView->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                     "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                     "display: flex;"
                                     "width: 484px;"
                                     "height: 60px;"
                                     "padding: 20px 16px;"
                                     "align-items: center;"
                                     "spacing: 24px;"
                                     "flex: 0;");*/
  ui->IDFOR->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                          "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                          "display: flex;"
                          "width: 484px;"
                          "height: 60px;"
                          "padding: 20px 16px;"
                          "align-items: center;"
                          "spacing: 24px;"
                          "flex: 0;");
ui->formateur->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                             "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                             "display: flex;"
                             "width: 484px;"
                             "height: 60px;"
                             "padding: 20px 16px;"
                             "align-items: center;"
                             "spacing: 24px;"
                             "flex: 0;");
ui->type->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                        "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                        "display: flex;"
                        "width: 484px;"
                        "height: 60px;"
                        "padding: 20px 16px;"
                        "align-items: center;"
                        "spacing: 24px;"
                        "flex: 0;");
ui->duree->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                         "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                         "display: flex;"
                         "width: 484px;"
                         "height: 60px;"
                         "padding: 20px 16px;"
                         "align-items: center;"
                         "spacing: 24px;"
                         "flex: 0;");
ui->debut->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                         "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                         "display: flex;"
                         "width: 484px;"
                         "height: 60px;"
                         "padding: 20px 16px;"
                         "align-items: center;"
                         "spacing: 24px;"
                         "flex: 0;");
ui->fin->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                       "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                       "display: flex;"
                       "width: 484px;"
                       "height: 60px;"
                       "padding: 20px 16px;"
                       "align-items: center;"
                       "spacing: 24px;"
                       "flex: 0;");
ui->nb_place->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
ui->ajouter_Confirm->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
ui->ajouter_Canel->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                 "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                 "display: flex;"
                                 "width: 484px;"
                                 "height: 60px;"
                                 "padding: 20px 16px;"
                                 "align-items: center;"
                                 "spacing: 24px;"
                                 "flex: 0;");


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_ajouter_clicked()
{
    ui->gestion_formation->hide();
    ui->ajouter_formation->show();


}

void MainWindow::on_pushButton_clicked()
{
    ui->gestion_formation->hide();
    ui->ajouter_formation->show();
}

void MainWindow::on_bt_return_clicked()
{
    ui->ajouter_formation->hide();
    ui->gestion_formation->show();
}



void MainWindow::on_ajouter_Canel_clicked()
{

     ui->IDFOR->clear();
ui->formateur->clear();

ui->duree->clear();
ui->debut->clear();
ui->fin->clear();
ui->nb_place->clear();


    //ui->ajouter_formation->hide();
   // ui->gestion_formation->show();
}

void MainWindow::on_ajouter_Confirm_clicked()
{
    int IDFOR=ui->IDFOR->text().toInt();
    QString formateur=ui->formateur->text();
    QString type_de_formation=ui->type->currentText();
    QString duree=ui->duree->text();
    QDate date_de_debut=ui->debut->date();
    QDate  date_de_fin=ui->fin->date();
    int nb_place=ui->nb_place->text().toInt();
    formation f(IDFOR,formateur,type_de_formation,date_de_debut,date_de_fin,duree,nb_place);

    bool test=f.ajouter();
       QMessageBox msgBox;
       if(test)
        {msgBox.setText("Ajout avec succes.");
              ui->tableView->setModel(f.afficher());
        }
        else
            msgBox.setText("echec d'ajout");
        msgBox.exec();
    ui->ajouter_formation->hide();
    ui->gestion_formation->show();
}

void MainWindow::on_supprimer_clicked()
{

        QString idString = ui->supp_id->text();
        if (idString.isEmpty()) {
            QMessageBox::warning(nullptr, QObject::tr("Invalid Input"), QObject::tr("Please enter an ID to delete."), QMessageBox::Ok);
            return;
        }

        int id = idString.toInt();
        formation f;

        if (!f.idExists(id)) {
            QMessageBox::warning(nullptr, QObject::tr("Invalid ID"), QObject::tr("The entered ID does not exist."), QMessageBox::Ok);
            return;
        }

        bool test = f.supprimer(id);

        QMessageBox msgBox;
        if (test) {
            msgBox.setText("Suppression réussie.");
            ui->tableView->setModel(f.afficher());
            ui->supp_id->clear();
        } else {
            msgBox.setText("Échec de la suppression.");
        }
        msgBox.exec();
    }



