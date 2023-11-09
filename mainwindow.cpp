#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"
#include "connexion.h"
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>
#include <QVBoxLayout>
#include<QGraphicsDropShadowEffect>
#include<QStackedWidget>
#include <QApplication>
#include <QLineEdit>
#include <QWidget>
#include <QPropertyAnimation>
#include <QPalette>
#include<QMessageBox>
#include<QObject>
#include<QIntValidator>
#include<QSqlTableModel>
#include <iostream>
#include <QTableView>
#include <QLinearGradient>
#include <QBrush>
#include<QAbstractTableModel>
#include <cstdlib>
#include <QPrinter>
#include <QTextDocument>
#include<iostream>
#include <fstream>
using namespace  std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //login
    ui->login_email->setClearButtonEnabled(true);
      ui->login_mdp->setClearButtonEnabled(true);
      //Password mode set
      ui->login_mdp->setEchoMode(QLineEdit::Password);

      QIcon email("/Users/Msi/Downloads/   Vector.png");
      QIcon password("/Users/Msi/Downloads/  padlock 1.png") ;

      ui->login_email->addAction(email,QLineEdit::LeadingPosition);
      ui->login_mdp->addAction(password,QLineEdit::LeadingPosition);

   // QObject::connect(ui->mid, QOverload<int>::of(&ui->mid::currentIndexChanged), this, &formation::QlineEdit);
ui->login_connecter->setEnabled(true) ;
    //ui->combo_id->addItem(IDFOR);
connect(ui->mid, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_mid_currentIndexChanged); // ++

    QString css="color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                "display: flex;"
                "width: 484px;"
                "height: 60px;"
                "padding: 20px 16px;"
                "align-items: center;"
                "spacing: 24px;"
                "flex: 0;";
QString css_btn="QPushButton"
"{"
    "background:none;"
    "text-align: center;"
   " padding-left:10px;"
    "border-radius: 10px;"

    "background-color :  rgba(189, 76, 224, 1);"
"color:#fff;"
    "font-family: Arial, sans-serif; "
  "  font-size: 20px;"
  "  font-weight: bold; "
"} "
"QPushButton:hover"
"{"
    "border : 2px solid  rgba(189, 76, 224, 1);	"
    "background-color: rgba(84, 16, 149, 1);"

"}";

    // Create a property animation for the notif_bar QLabel
            QPropertyAnimation* animation = new QPropertyAnimation(ui->notif_bar, "geometry", this);
            animation->setDuration(10000); // Duration in milliseconds
            animation->setStartValue(QRect(40, 20, 1840, 60)); // Initial position
          animation->setEndValue(QRect(1700, 20, 1700, 60)); // Final position
            animation->setEasingCurve(QEasingCurve::Linear); // Linear movement
            animation->setLoopCount(200); // Run the animation once
            animation->start();

ui->login_mdp->setEchoMode(QLineEdit::Password);

ui->login_email->setStyleSheet(css);
ui->login_mdp->setStyleSheet(css);
ui->back_notif_bar->setStyleSheet(css);
ui->bt_rechercher->setStyleSheet(css_btn);
ui->texte_recherche->setStyleSheet(css);
ui->PDF->setStyleSheet(css_btn);
ui->STATISTIQUE->setStyleSheet(css_btn);
ui->TRI->setStyleSheet(css_btn);
ui->login_connecter->setStyleSheet(css_btn);
    ui->IDFOR->setValidator(new QIntValidator(100,9999,this));
    ui->nb_place->setValidator(new QIntValidator(100,9999,this));
    QRegExp regex("[a-z]+", Qt::CaseInsensitive);
    QRegExpValidator* validator = new QRegExpValidator(regex, this);
    ui->formateur->setValidator(validator);
    ui->tableView->setStyleSheet("QTableView{color: white; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                                   "display: flex;"
                                                   "width: 484px;"
                                                   "height: 60px;"
                                                   "padding: 20px 16px;"
                                                   "align-items: center;"
                                                   "spacing: 24px;"
                                                   "flex: 0;}"
                                                    " color: white; background-color: rgba(0, 0, 0, 0.5); ");
    ui->tableView->setModel(f.afficher());
    ui->login_show->hide();
ui->label_32->hide();
    ui->gestion_formation->hide();
    ui->ajouter_formation->hide();
    ui->modifier_formation->hide();
    ui->creer->hide();
    ui->login->show();


    // x
    ui->IDFOR->setClearButtonEnabled(true);
      ui->formateur->setClearButtonEnabled(true);
      ui->duree->setClearButtonEnabled(true);
        ui->nb_place->setClearButtonEnabled(true);

        QSqlQuery query;
            query.exec("SELECT IDFOR FROM formation");

            // Populate the combobox with data from the database
            while (query.next()) {
                int id = query.value(0).toInt();
                ui->combo_id->addItem(QString::number(id));
            }

        //size
        setFixedSize(1920,1080);

//stylesheet lineEdit
        /*ui->tableView->setStyleSheet( css);*/
ui->ajouter->setStyleSheet(css_btn);
ui->combo_id->setStyleSheet(css);
ui->bt_modifier->setStyleSheet(css_btn);



  ui->IDFOR->setStyleSheet( css);
ui->formateur->setStyleSheet( css);
ui->type->setStyleSheet( css);
ui->duree->setStyleSheet( css);
ui->debut->setStyleSheet( css);
ui->fin->setStyleSheet( css);
ui->nb_place->setStyleSheet( css);
ui->ajouter_Confirm->setStyleSheet(css_btn);
ui->ajouter_Canel->setStyleSheet(css_btn);

ui->supprimer->setStyleSheet(css_btn);

ui->mid->setStyleSheet( css);
ui->mformateur->setStyleSheet( css);
ui->mtype->setStyleSheet( css);
ui->mduree->setStyleSheet( css);
ui->mdebut->setStyleSheet( css);
ui->mfin->setStyleSheet( css);
ui->mnbplace->setStyleSheet( css);
ui->mconfirm->setStyleSheet(css_btn);
ui->mannuler->setStyleSheet(css_btn);


}
void MainWindow::init()
{
    connect(ui->mid, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_mid_currentIndexChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    //setdate
    ui->debut->setDateTime(QDateTime::currentDateTime());
    ui->fin->setDateTime(QDateTime::currentDateTime());

    ui->gestion_formation->hide();
    ui->modifier_formation->hide();
    ui->ajouter_formation->show();

}

void MainWindow::on_bt_return_clicked()
{
    ui->ajouter_formation->hide();
    ui->modifier_formation->hide();
    ui->gestion_formation->show();
}



void MainWindow::on_ajouter_Canel_clicked()
{

ui->IDFOR->clear();
ui->formateur->clear();
 ui->type->setCurrentIndex(0);
ui->duree->clear();
ui->debut->clear();
ui->fin->clear();
ui->nb_place->clear();


    //ui->ajouter_formation->hide();
   // ui->gestion_formation->show();
}

void MainWindow::on_ajouter_Confirm_clicked()
{
    int c=0;//nb  du faute dans controle saisie
    int IDFOR=ui->IDFOR->text().toInt();
    QString formateur=ui->formateur->text();
    QString type_de_formation=ui->type->currentText();
    QString duree=ui->duree->text();
    QDate date_de_debut=ui->debut->date();
    QDate  date_de_fin=ui->fin->date();
   QDate min = QDate::fromString("2023-11-04", "yyyy-MM-dd");
    int nb_place=ui->nb_place->text().toInt();
    //controle de saisie
    if(f.idExists(IDFOR))
    {
        c++;
        QMessageBox::warning(nullptr, QObject::tr("Invalide ID"), QObject::tr("ID already exist"), QMessageBox::Ok);
        return;

    }
    if(IDFOR==0  )
    {

        c++;
        QMessageBox::warning(nullptr, QObject::tr("Invalide ID"), QObject::tr("dont put 0"), QMessageBox::Ok);
        return;
    }
    if(ui->IDFOR->text().isEmpty())
    {

        c++;
        QMessageBox::warning(nullptr, QObject::tr("Invalide ID"), QObject::tr("you cant put empty ID"), QMessageBox::Ok);
        return;
    }

    if(nb_place<3 )
       {
        c++;
        QMessageBox::warning(nullptr, QObject::tr("Invalide Nb_place"), QObject::tr("Veuillez entrer 3 ou plus place"), QMessageBox::Ok);
        return;}
   if(date_de_debut<min)
   {
       c++;
       QMessageBox::warning(nullptr, QObject::tr("Invalide date de debut"), QObject::tr("Veuillez entrer une autre date"), QMessageBox::Ok);
       return;
   }
    if(date_de_fin<date_de_debut)
    {
     c++;
     QMessageBox::warning(nullptr, QObject::tr("Invalide date"), QObject::tr("la date de fin doit être supérieure à la date de début  "), QMessageBox::Ok);

     return;}
if(formateur=="")
   {
    c++;
    QMessageBox::warning(nullptr, QObject::tr("Invalide Formateur nom"), QObject::tr("Donner un nom du formateur"), QMessageBox::Ok);

    return;

}


    if(c==0) //si il n' y a pas problem dans le controle de saisie
    {formation f(IDFOR,formateur,type_de_formation,date_de_debut,date_de_fin,duree,nb_place);

    bool test=f.ajouter();
       QMessageBox msgBox;
       if(test)
        {msgBox.setText("Ajout avec succes.");
              ui->tableView->setModel(f.afficher());
              QSqlQuery query;
              ui->combo_id->clear();
                  query.exec("SELECT IDFOR FROM formation");
                  while (query.next()) {
                      int id = query.value(0).toInt();
                      ui->combo_id->addItem(QString::number(id));}
              ui->IDFOR->clear();
         ui->formateur->clear();
        ui->type->setCurrentIndex(0);
         ui->duree->clear();
         ui->debut->clear();
         ui->fin->clear();
         ui->nb_place->clear();
        }
        else
            msgBox.setText("echec d'ajout");
        msgBox.exec();

    ui->ajouter_formation->hide();
    ui->modifier_formation->hide();
    ui->gestion_formation->show();
    }
}

void MainWindow::on_supprimer_clicked()
{


    QString id_string=ui->combo_id->currentText();
int id=id_string.toInt();


bool test = f.supprimer(id);

        QMessageBox msgBox;
        if (test) {
            msgBox.setText("Suppression réussie.");
            ui->tableView->setModel(f.afficher());
            QSqlQuery query;
                 ui->combo_id->clear();
                query.exec("SELECT IDFOR FROM formation");
                while (query.next()) {
                    int id = query.value(0).toInt();
                    ui->combo_id->addItem(QString::number(id));}
        } else {
            msgBox.setText("Échec de la suppression.");

        }
        msgBox.exec();
    }



void MainWindow::on_bt_mreturn_clicked()
{
    ui->modifier_formation->hide();
    ui->ajouter_formation->hide();
    ui->gestion_formation->show();
}

void MainWindow::on_TRI_clicked()
{
    QSqlQueryModel* sortedModel =f.tri();

      // Assuming you have a member variable `tableView` of type QTableView in the MainWindow class
     ui->tableView->setModel(sortedModel);

      // Adjust the header view as needed
    QHeaderView* headerView = ui->tableView->horizontalHeader();
      headerView->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_bt_rechercher_clicked()
{
        QString formateur=ui->texte_recherche->text();


           QSqlQueryModel* searchModel = new QSqlQueryModel();
           searchModel->setQuery("SELECT * FROM formation WHERE FORMATEUR LIKE '%" + formateur + "%'");

           if (searchModel->rowCount() > 0) {
               // If the search result is not empty
               ui->tableView->setModel(searchModel);

               // Adjust the header view as needed
               QHeaderView* headerView = ui->tableView->horizontalHeader();
               headerView->setSectionResizeMode(QHeaderView::Stretch);
           } else {
               // If the search result is empty
               QMessageBox::information(this, "Search Result", "FORMATEUR does not exist.");
           }


}

void MainWindow::on_refresh_clicked()
{

  ui->tableView->setModel(f.afficher());
 ui-> texte_recherche->clear();
 //notification
 QDate currentDate = QDate::currentDate();
 QDate closestDate;

 // Find the closest DATE_DE_DEBUT
 QSqlQuery query;
 query.exec("SELECT DATE_DE_DEBUT FROM formation WHERE DATE_DE_DEBUT >= '" + currentDate.toString("yyyy-MM-dd") + "' ORDER BY DATE_DE_DEBUT ASC LIMIT 1");

 if (query.next())
 {
     closestDate = query.value(0).toDate();
     int daysLeft = currentDate.daysTo(closestDate);
     while (query.next()) {
         qDebug() << "Found DATE_DE_DEBUT: " << query.value(0).toDate().toString("dd/MM/yyyy");
     }
     if (daysLeft >= 0) {
         // Display the closest DATE_DE_DEBUT on the QLabel
         ui->notif_bar->setText("Closest DATE_DE_DEBUT: " + closestDate.toString("dd/MM/yyyy"));

         // Display the number of days left until the next formation
         QString message = "Days left until the next formation: " + QString::number(daysLeft);
         // QMessageBox::information(this, "Next Formation", message);
     } else {
         // If the closest DATE_DE_DEBUT is in the past
         ui->notif_bar->setText("No upcoming formations /");
     }
 }
 else {
     // If no future DATE_DE_DEBUT is found
     ui->notif_bar->setText("No upcoming formations");
     // QMessageBox::information(this, "Next Formation", "No upcoming formations");
 }

}

void MainWindow::on_login_connecter_clicked()
{
    QString email = ui->login_email->text();
     QString password = ui->login_mdp->text();

     // Perform database query to check email and password
     // Assuming you have a QSqlDatabase object named "database" set up

     QSqlQuery query;
     query.prepare("SELECT * FROM compte WHERE IDP = :email");
     query.bindValue(":email", email);

     if (query.exec() && query.next()) {
         // User record found
         QString storedPassword = query.value("MDP").toString();
         if (password == storedPassword) {
             // Password matched
             // Proceed with successful login
             ui->login->hide();
             ui->ajouter_formation->hide();
             ui->gestion_formation->show();
         } else {
             // Password is incorrect
             QMessageBox::critical(this, "Error", "Incorrect password");
         }
     } else {
         // User record not found
         QMessageBox::critical(this, "Error", "Incorrect email");
     }
}

void MainWindow::on_pushButton_clicked()
{
    ui->login->hide();
    ui->ajouter_formation->hide();
    ui->gestion_formation->hide();
    ui->creer->show();
}


void MainWindow::on_creer_confirmer_clicked()
{
    QString email = ui->creer_email->text();
    QString password = ui->creer_mdp->text();

    // Perform database query to check if email already exists
    // Assuming you have a QSqlDatabase object named "database" set up

    QSqlQuery query;
    query.prepare("SELECT * FROM compte WHERE IDP = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        // Email already exists
        QMessageBox::critical(this, "Error", "Email already exists");
    } else {
        // Email doesn't exist, proceed with account creation
        query.prepare("INSERT INTO compte (IDP, MDP) VALUES (:email, :password)");
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (query.exec()) {
            // Account creation successful
            QMessageBox::information(this, "Success", "Account created successfully");
        } else {
            // Account creation failed
            QMessageBox::critical(this, "Error", "Failed to create account");
        }
    }

    ui->ajouter_formation->hide();
    ui->gestion_formation->hide();
    ui->creer->hide();
    ui->login->show();
}



void MainWindow::on_login_show_clicked()
{
    ui->login_hide->hide();
    ui->login_show->show();
    ui->login_mdp->setEchoMode(QLineEdit::Normal);
}

void MainWindow::on_PDF_clicked()
{


    // Associez le modèle à votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());

    if (model) {
        QString content;
        //header
        for (int col = 0; col < model->columnCount(); ++col) {

             content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                }
        content += "\n";
        // Parcourez les données du modèle et ajoutez-les au contenu
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                content += model->data(model->index(row, col)).toString() + "\t";
            }
            content += "\n";
        }

        // Créez un objet QTextDocument et définissez son contenu
        QTextDocument document;
        document.setPlainText(content);

        // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/MSI/formation", "Fichiers PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            // Créez un objet QPrinter pour générer le PDF.
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Imprimez le document sur le PDF.
            document.print(&printer);

            // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
            QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
        }
    }
}
int MainWindow::countType(const QString& type)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(\"TYPE\") FROM formation WHERE \"TYPE\" = :type");
    query.bindValue(":type", type);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}

void MainWindow::on_STATISTIQUE_clicked()
{
    QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
        for (QWidget* childWidget : childWidgets) {
            childWidget->deleteLater();

        }
        //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
        ui->label_32->clear();
        ui->label_32->hide();

    float s0=0, s1=0, s2=0, s3=0, s4=0;
    s0 = countType("leadership");
    s1 = countType("initiale");
    s3 = countType("continue");
    s3 = countType("sectorielle");
    s4 = countType("technologies de l'information");

    float stat = s0 + s1 + s2 + s3 + s4;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;
    float z = (stat != 0) ? (s2 * 100) / stat : 0.0;
    float d = (stat != 0) ? (s3 * 100) / stat : 0.0;
    float w = (stat != 0) ? (s4 * 100) / stat : 0.0;
qDebug() << s2 <<endl;
qDebug() << s1 <<endl;
    QString ch1 = QString("leadership %1%").arg(x);
    QString ch2 = QString("initiale %1%").arg(y);
    QString ch3 = QString("continue %1%").arg(z);
    QString ch4 = QString("sectorielle %1%").arg(d);
    QString ch5 = QString("technologies %1%").arg(w);

        QPieSeries *series=new QPieSeries();
        series->setHoleSize(0.35);



        QPieSlice *slice= series->append(ch1,x);
        slice->setLabelVisible();
        slice->setLabelColor(QColor("#FFFFFF"));
            slice->setBrush(QColor(189, 76, 224, 1));
        QPieSlice *slice1= series->append(ch2,y);
        slice1->setLabelVisible();
        slice1->setLabelColor(QColor("#FFFFFF"));
        slice1->setBrush(QColor(84, 16, 149, 1));
        QPieSlice *slice2= series->append(ch3,z);
        slice2->setLabelVisible();

        slice2->setLabelColor(QColor(Qt::white));
        slice2->setBrush(QColor(Qt::white));
        QPieSlice *slice3= series->append(ch4,d);
        slice3->setLabelVisible();
        slice3->setLabelColor(QColor(Qt::white));
        slice3->setBrush(QColor(Qt::blue));
        QPieSlice *slice4= series->append(ch5,w);
        slice4->setLabelVisible();
        slice4->setLabelColor(QColor(Qt::white));
        slice4->setBrush(QColor(Qt::red));


        QChart *chart=new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        //chart->setTitle("Statistique entre l homme et la femme");
        //chart->setTheme(QChart::ChartThemeQt);
        QBrush backgroundBrush(QColor(187,93,87,0));
        chart->setBackgroundBrush(backgroundBrush);
        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setFixedSize(ui->label_32->size());
        chartview->setParent(ui->label_32);
      ui->label_32->setStyleSheet("background:transparent; color:white; ");
        ui->label_32->show();

}
void MainWindow::on_bt_modifier_clicked()
{
    // Get the selected ID from the combo box

    QSqlQuery query;
    ui->mid->clear();
    query.exec("SELECT IDFOR FROM formation");
    while (query.next()) {
        int id = query.value(0).toInt();
        ui->mid->addItem(QString::number(id));
    }
      int selectedId = ui->mid->currentText().toInt();
    // Call the function to update the UI with the selected ID's data
    updateUI(selectedId);

    // Show the appropriate UI elements
    ui->gestion_formation->hide();
    ui->ajouter_formation->hide();
    ui->modifier_formation->show();
}

void MainWindow::on_mid_currentIndexChanged(int index)
{
    // Get the selected ID from the combo box
    int selectedId = ui->mid->itemText(index).toInt();

    // Call the function to update the UI with the selected ID's data
    updateUI(selectedId);

    // Show the appropriate UI elements
    ui->gestion_formation->hide();
    ui->ajouter_formation->hide();
    ui->modifier_formation->show();
}

void MainWindow::updateUI(int selectedId)
{
    QSqlQuery query;

    // Retrieve and set values for other UI elements based on the selected ID
    query.prepare("SELECT FORMATEUR, NB_PLACE, TYPE, DUREE, DATE_DE_DEBUT, DATE_DE_FIN FROM formation WHERE IDFOR = :id");
    query.bindValue(":id", selectedId);

    if (query.exec() && query.next()) {
        QString formateur = query.value(0).toString();
        QString NB_PLACE = query.value(1).toString();
        QString type = query.value(2).toString();
        QString duree = query.value(3).toString();
        QDateTime debut = query.value(4).toDateTime();
        QDateTime fin = query.value(5).toDateTime();

        // Update the UI elements with the retrieved data
        ui->mformateur->setText(formateur);
        ui->mnbplace->setText(NB_PLACE);

        int index = ui->mtype->findText(type);
        if (index != -1) {
            ui->mtype->setCurrentIndex(index);
        }

        ui->mduree->setText(duree);
        ui->mdebut->setDateTime(debut);
        ui->mfin->setDateTime(fin);
    }
}



void MainWindow::on_mannuler_clicked()
{
    ui->modifier_formation->hide();
     ui->gestion_formation->show();
}



void MainWindow::on_hide_clicked()
{
    ui->login_hide->hide();
ui->login_show->show();
  ui->login_mdp->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_mconfirm_clicked()
{
    //formation f;
    int c=0;
        // Get the values from the UI elements
    int IDFOR=ui->mid->currentText().toInt();
    QString formateur=ui->mformateur->text();
    QString type_de_formation=ui->mtype->currentText();
    QString duree=ui->mduree->text();
    QDate date_de_debut=ui->mdebut->date();
    QDate  date_de_fin=ui->mfin->date();
    int nb_place=ui->mnbplace->text().toInt();
     QDate min = QDate::fromString("2023-11-04", "yyyy-MM-dd");
    if(nb_place<3 )
       {
        c++;
        QMessageBox::warning(nullptr, QObject::tr("Invalide Nb_place"), QObject::tr("Veuillez entrer 3 ou plus place"), QMessageBox::Ok);
        return;}
   if(date_de_debut<min)
   {
       c++;
       QMessageBox::warning(nullptr, QObject::tr("Invalide date de debut"), QObject::tr("Veuillez entrer une autre date"), QMessageBox::Ok);
       return;
   }
    if(date_de_fin<date_de_debut)
    {
     c++;
     QMessageBox::warning(nullptr, QObject::tr("Invalide date"), QObject::tr("la date de fin doit être supérieure à la date de début  "), QMessageBox::Ok);

     return;}
if(formateur=="")
   {
    c++;
    QMessageBox::warning(nullptr, QObject::tr("Invalide Formateur nom"), QObject::tr("Donner un nom du formateur"), QMessageBox::Ok);

    return;

}

if(c==0)
{
        // Update the record in the database

        bool test = f.modifier(IDFOR,formateur,type_de_formation,duree,date_de_debut,date_de_fin,nb_place);

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification successful.\n""Click cancel to exit."), QMessageBox::Cancel);

            ui->tableView->setModel(f.afficher()); // Refresh your table view after modification
            ui->modifier_formation->hide();
            ui->gestion_formation->show();
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification failed.\n""Click cancel to exit."), QMessageBox::Cancel);
        }
}
}

void MainWindow::on_login_hide_clicked()
{
    ui->login_show->hide();
ui->login_hide->show();
  ui->login_mdp->setEchoMode(QLineEdit::Password);
}
