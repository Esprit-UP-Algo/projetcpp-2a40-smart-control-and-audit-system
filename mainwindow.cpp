#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->bouton_menu->setStyleSheet();
    ui->groupBox->show();
    ui->ajout_entreprise->hide();
ui->table_entreprise->setModel(e.afficher());
    ui->l_id->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_nom->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_email->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_specialite->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_adresse->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_reception->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->l_etat->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->enregistrer->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->annuler->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->ajouter->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
    ui->supprimer->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 24px;"
                           "flex: 0;");
            ui->supprimer_2->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_2->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_nom->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_adresse->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_email->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_reception->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_etat->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->modifier_specialite->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->bou_modifier->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->bou_annuler->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 20px 16px;"
                                   "align-items: center;"
                                   "spacing: 24px;"
                                   "flex: 0;");
            ui->table_entreprise->setStyleSheet("QTableView{color: white; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                               "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                               "display: flex;"
                                               "width: 484px;"
                                               "height: 60px;"
                                               "padding: 20px 16px;"
                                               "align-items: center;"
                                               "spacing: 24px;"
                                               "flex: 0;}"
                                                " color: white; background-color: rgba(0, 0, 0, 0.5); ");


            ui->supprimer_2->setPlaceholderText("Entrez l'id de l'entreprise à supprimer ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_id->setPlaceholderText("Entrez l'id de l'entreprise ");
            ui->l_email->setPlaceholderText("Entrez l'e nom de'Email de l'entreprise ");
            ui->l_specialite->setPlaceholderText("Entrez la specialité de l'entreprise ");
            ui->l_reception->setPlaceholderText("Entrez la reception de la demande ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_adresse->setPlaceholderText("Entrez l'e nom'adresse de l'entreprise ");
            ui->l_etat->setPlaceholderText("Entrez l'etat de l'entreprise ");
            ui->modifier_2->setPlaceholderText("Entrez l'id de l'entreprise à modifier ");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->ajout_entreprise->hide();
    ui->groupBox->show();
}

void MainWindow::on_ajouter_clicked()
{
    ui->ajout_entreprise->show();
    ui->groupBox->hide();
}

void MainWindow::on_enregistrer_clicked()
{
        int id=ui->l_id->text().toInt();
        QString nom = ui->l_nom->text();
        QString email=ui->l_email->text();
        QString specialite = ui->l_specialite->text();
        QString adresse=ui->l_adresse->text();
        QString reception_de_la_demande=ui->l_reception->text();
        QString etat=ui->l_etat->text();
        Entreprise e(id,nom,email,specialite,adresse,reception_de_la_demande,etat);
        bool test=e.ajouter();
        if(test)
        {
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout successful.\n""Click cancel to exit."),QMessageBox::Cancel);
             ui->table_entreprise->setModel(e.afficher());

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout failed.\n""Click cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_supprimer_clicked()
{

    QString idString = ui->supprimer_2->text();
        if (idString.isEmpty()) {
            QMessageBox::warning(nullptr, QObject::tr("Invalid Input"), QObject::tr("Please enter an ID to delete."), QMessageBox::Ok);
            return;
        }

        Entreprise e1;
        e1.setid(idString.toInt());
        QString queryStr = "SELECT id FROM entreprise WHERE id = :id";
        QSqlQuery query;
        query.prepare(queryStr);
        query.bindValue(":id", e1.getid());
        bool exists = query.exec() && query.next();

        if (!exists) {
            QMessageBox::warning(nullptr, QObject::tr("ID Not Found"), QObject::tr("The entered ID does not exist."), QMessageBox::Ok);
            return;
        }

        bool test = e1.supprimer(e1.getid());

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression successful.\n""Click cancel to exit."), QMessageBox::Cancel);
            ui->table_entreprise->setModel(e.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression failed.\n""Click cancel to exit."), QMessageBox::Cancel);
        }
}
void MainWindow::on_annuler_clicked()
{
    ui->l_id->clear();
    ui->l_nom->clear();
    ui->l_email->clear();
    ui->l_specialite->clear();
    ui->l_adresse->clear();
    ui->l_reception->clear();
    ui->l_etat->clear();
}

void MainWindow::on_modifier_clicked()
{

    QString idString = ui->modifier_2->text();
        if (idString.isEmpty()) {
            QMessageBox::warning(nullptr, QObject::tr("Invalid Input"), QObject::tr("Please enter an ID to modify."), QMessageBox::Ok);
            return;
        }

        Entreprise e1;
        e1.setid(idString.toInt());
        QString queryStr = "SELECT id FROM entreprise WHERE id = :id";
        QSqlQuery query;
        query.prepare(queryStr);
        query.bindValue(":id", e1.getid());
        bool exists = query.exec() && query.next();

        if (!exists) {
            QMessageBox::warning(nullptr, QObject::tr("ID Not Found"), QObject::tr("The entered ID does not exist."), QMessageBox::Ok);
            return;
        }
        ui->ajout_entreprise->show();
        ui->groupBox->hide();

       /* Afficher la nouvelle interface pour la saisie des nouvelles informations
       showModifyInterface(id);*/
}
