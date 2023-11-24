#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"
#include "connexion.h"
#include "arduino.h"
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
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <Windows.h>
#include <QDesktopServices>
#include <QUrl>

using namespace  std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setWindowFlags(Qt::CustomizeWindowHint);
    ui->bt_historique->hide();


    //connect arduino
    arduino a;
    int ret = a.connect_arduino();

    switch (ret) {
        case 0:
            qDebug() << "Arduino is available and connected on:" << a.getarduino_port_name();
            break;
        case 1:
            qDebug() << "Arduino is available but not connected on:" << a.getarduino_port_name();
            break;
        case -1:
            qDebug() << "Arduino is not available";
            break;
    }



    // Show a message on the LCD
    QString message = "Welcome to my program!";
    a.show_message_on_lcd(message);
    //login
    ui->login_email->setClearButtonEnabled(true);
      ui->login_mdp->setClearButtonEnabled(true);
      //Password mode set
      ui->login_mdp->setEchoMode(QLineEdit::Password);

      QIcon email("/Users/Msi/Downloads/Vector.png");
      QIcon password("/Users/Msi/Downloads/padlock 1.png") ;

      ui->login_email->addAction(email,QLineEdit::LeadingPosition);
      ui->login_mdp->addAction(password,QLineEdit::LeadingPosition);

   // QObject::connect(ui->mid, QOverload<int>::of(&ui->mid::currentIndexChanged), this, &formation::QlineEdit);
ui->login_connecter->setEnabled(true) ;
    //ui->combo_id->addItem(IDFOR);
//connect(ui->mid, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_mid_currentIndexChanged);
connect(ui->texte_recherche, &QLineEdit::textChanged, this, &MainWindow::on_texte_recherche_textChanged);
connect(ui->afficher_historique, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxhistorique);
// ++

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


ui->notif_bar->setStyleSheet("color: rgb(189, 76, 224);");

// Create a property animation for the notif_bar QLabel
QPropertyAnimation* animation = new QPropertyAnimation(ui->notif_bar, "geometry", this);
animation->setDuration(10000); // Duration in milliseconds
animation->setStartValue(QRect(40, 20, 1840, 60)); // Initial position
animation->setEndValue(QRect(1700, 20, 1700, 60)); // Final position
animation->setEasingCurve(QEasingCurve::Linear); // Linear movement
animation->setLoopCount(1000); // Run the animation once
animation->start();


Notification();

ui->login_mdp->setEchoMode(QLineEdit::Password);

ui->login_email->setStyleSheet(css);
ui->login_mdp->setStyleSheet(css);
ui->creer_email->setStyleSheet(css);
ui->creer_mdp->setStyleSheet(css);
ui->creer_confirmer->setStyleSheet(css_btn);
ui->back_notif_bar->setStyleSheet(css);
ui->texte_recherche->setStyleSheet(css);
ui->combo_id->setStyleSheet(css);
ui->PDF->setStyleSheet(css_btn);


ui->login_connecter->setStyleSheet(css_btn);
    ui->IDFOR->setValidator(new QIntValidator(100,9999,this));
    ui->nb_place->setValidator(new QIntValidator(100,9999,this));
    QRegExp regex("[a-z]+", Qt::CaseInsensitive);
    QRegExpValidator* validator = new QRegExpValidator(regex, this);
    ui->formateur->setValidator(validator);
    ui->tableView->setStyleSheet("QTableView{color:#DCBFFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
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
    ui->acceuil->hide();
    ui->ajouter_formation->hide();
    ui->modifier_formation->hide();
    ui->creer->hide();
     ui->gestion_formation->hide();
     ui->historique->hide();
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
ui->ajouter->setStyleSheet("background-color:transparent;color:white;");
ui->TRI->setStyleSheet("background-color:transparent;color:white;");

ui->bt_modifier->setStyleSheet("background-color:transparent;color:white;");



  ui->IDFOR->setStyleSheet( css);
ui->formateur->setStyleSheet( css);
ui->type->setStyleSheet( css);
ui->duree->setStyleSheet( css);
ui->debut->setStyleSheet( css);
ui->fin->setStyleSheet( css);
ui->nb_place->setStyleSheet( css);
ui->ajouter_Confirm->setStyleSheet(css_btn);
ui->ajouter_Canel->setStyleSheet(css_btn);

ui->supprimer->setStyleSheet("background-color:transparent;color:white;");

ui->mid->setStyleSheet( css);
ui->mformateur->setStyleSheet( css);
ui->mtype->setStyleSheet( css);
ui->mduree->setStyleSheet( css);
ui->mdebut->setStyleSheet( css);
ui->mfin->setStyleSheet( css);
ui->mnbplace->setStyleSheet( css);
ui->mconfirm->setStyleSheet(css_btn);
ui->mannuler->setStyleSheet(css_btn);


STATISTIQUE();
on_notification_system();
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



void MainWindow::on_ajouter_Cancel_clicked()
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
              Notification();
              // Write to the "ajout" file
                      QFile file("/Users/Msi/OneDrive/Bureau/ajout.txt");
                      if (file.open(QIODevice::Append | QIODevice::Text)) {
                          QTextStream stream(&file);
                          stream << "ID added: " << IDFOR << ", Time: " << QDateTime::currentDateTime().toString() << endl;
                          file.close();
                      }
              QSqlQuery query;
              ui->combo_id->clear();
              STATISTIQUE();
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
            Notification();
            // Write to the "supprimer" file
                    QFile file("/Users/Msi/OneDrive/Bureau/suppression.txt");
                    if (file.open(QIODevice::Append | QIODevice::Text)) {
                        QTextStream stream(&file);
                        stream << "ID deleted: " << id << ", Time: " << QDateTime::currentDateTime().toString() << endl;
                        file.close();
                    }
            QSqlQuery query;
                 ui->combo_id->clear();
                query.exec("SELECT IDFOR FROM formation");
                while (query.next()) {
                    int id = query.value(0).toInt();
                    ui->combo_id->addItem(QString::number(id));
                STATISTIQUE();}
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

void MainWindow::on_texte_recherche_textChanged(const QString &text)
{
    QSqlQueryModel* searchModel = new QSqlQueryModel();
    searchModel->setQuery("SELECT * FROM formation WHERE FORMATEUR LIKE '%" + text + "%'");

    if (searchModel->rowCount() > 0) {
        // If the search result is not empty
        ui->tableView->setModel(searchModel);
    }
    if (searchModel->rowCount() == 0) {
        // If the search result is not empty
        ui->tableView->setModel(searchModel);
    }
        // Adjust the header view as needed
        QHeaderView* headerView = ui->tableView->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::on_refresh_clicked()
{

  ui->tableView->setModel(f.afficher());
 ui-> texte_recherche->clear();


}

void MainWindow::on_login_connecter_clicked()
{
    QString email = ui->login_email->text();
     QString password = ui->login_mdp->text();

     QSqlQuery query;
     query.prepare("SELECT * FROM EMPLOYE WHERE EMAIL = :email");
     query.bindValue(":email", email);

     if (query.exec() && query.next()) {

         QString storedPassword = query.value("MDP").toString();
         if (password == storedPassword) {

             query.prepare("SELECT POSTE FROM EMPLOYE WHERE EMAIL = :email");
             query.bindValue(":email", email);

             if (query.exec() && query.next())
             f.setROLE ( query.value("POSTE").toString());
             ui->login_email->clear();
             ui->login_mdp->clear();
             ui->login->hide();
             ui->acceuil->show();
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
    ui->login_show->hide();
    ui->login_hide->show();
    ui->login_mdp->setEchoMode(QLineEdit::Password);
}



void MainWindow::on_PDF_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           "<title>%1</title>\n"
           "<style>\n"
           "table {\n"
           "    width: 100%;\n"
           "    border-collapse: collapse;\n"
           "}\n"
           "th, td {\n"
           "    padding: 8px;\n"
           "    text-align: left;\n"
           "    border-bottom: 1px solid #ddd;\n"
           "}\n"
           "tr:nth-child(even) {\n"
           "    background-color: #f2f2f2;\n"
           "}\n"
           "</style>\n"
           "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<center> <H1>Liste des Formations</H1></center><br/><br/>\n"
           "<table>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableView->isColumnHidden(column))
        {
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView->isColumnHidden(column))
            {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }

    out << "</table>\n"
           "<br/><br/><center><img src=\"C:/Users/Msi/Downloads/logo pdf.png\"></center>\n" // Add the logo image tag here
           "</body>\n"
           "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
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

void MainWindow::STATISTIQUE()
{
    QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
        for (QWidget* childWidget : childWidgets) {
            childWidget->deleteLater();

        }
        //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
        ui->label_32->clear();
        ui->label_32->hide();

    int s0, s1, ss, s3;

    s0 = countType("Leadership");
    s1 = countType("Initiale");
    ss = countType("Continue");
    s3 = countType("Sectorielle");


    int stat = s0 + s1 + ss + s3 ;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float x1 = (stat != 0) ? (s1 * 100) / stat : 0.0;
    float x2 = (stat != 0) ? (ss * 100) / stat : 0.0;
    float x3 = (stat != 0) ? (s3 * 100) / stat : 0.0;

//qDebug() << ss <<endl;
//qDebug() << x2 <<endl;
    QString ch1 = QString("leadership %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("initiale %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("continue %3%").arg(QString::number(x2, 'f', 2));
  QString ch4 = QString("sectorielle %4%").arg(QString::number(x3, 'f', 2));


    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);



    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor("#FFFFFF"));
        slice->setBrush(QColor(189, 76, 224, 1));
    QPieSlice *slice1= series->append(ch2,x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor("#FFFFFF"));
    slice1->setBrush(QColor(84, 16, 149, 1));
    QPieSlice *slice2= series->append(ch3,x2);
    slice2->setLabelVisible();

    slice2->setLabelColor(QColor(Qt::white));
    slice2->setBrush(QColor(119, 82, 254));
    QPieSlice *slice3= series->append(ch4,x3);
    slice3->setLabelVisible();
    slice3->setLabelColor(QColor(Qt::white));
    slice3->setBrush(QColor(77, 76, 125));



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
    int selectedId = ui->combo_id->currentText().toInt();

    // Call the function to update the UI with the selected ID's data
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
        ui->mid->setText(ui->combo_id->currentText());
        ui->mformateur->setText(formateur);
        ui->mnbplace->setText(NB_PLACE);

        int index = ui->mtype->findText(type);
        if (index != -1) {
            ui->mtype->setCurrentIndex(index);
        }

        ui->mduree->setText(duree);
        ui->mdebut->setDateTime(debut);
        ui->mfin->setDateTime(fin);

    // Show the appropriate UI elements
    ui->gestion_formation->hide();
    ui->ajouter_formation->hide();
    ui->modifier_formation->show();
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
int IDFOR=ui->mid->text().toInt();
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
        Notification();
        // Write to the "modification" file
                QFile file("/Users/Msi/OneDrive/Bureau/modification.txt");
                if (file.open(QIODevice::Append | QIODevice::Text)) {
                    QTextStream stream(&file);
                    stream << "ID modifier: " << IDFOR << ", Time: " << QDateTime::currentDateTime().toString() << endl;
                    file.close();
                }

        ui->tableView->setModel(f.afficher());// Refresh your table view after modification
         STATISTIQUE();
        ui->modifier_formation->hide();
        ui->gestion_formation->show();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification failed.\n""Click cancel to exit."), QMessageBox::Cancel);
    }
}
}

void MainWindow::on_login_hide_clicked()
{
ui->login_hide->hide();
ui->login_show->show();
ui->login_mdp->setEchoMode(QLineEdit::Normal);
}

void MainWindow::on_acceuil_gestion_employe_clicked()
{
   QString ROLE=f.getROLE();

   if(ROLE == "EMPLOYE" || ROLE == "ADMIN")
   {ui->acceuil->hide();
       ui->gestion_formation->show();
   }
   else
   {
  QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion employe");
   }

}

void MainWindow::on_acceuil_gestion_entreprise_clicked()
{
    QString ROLE=f.getROLE();

    if(ROLE == "ENTREPRISE" || ROLE == "ADMIN")
    {ui->acceuil->hide();
        ui->gestion_formation->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion entreprise");
    }
}

void MainWindow::on_acceuil_gestion_inspection_clicked()
{
    QString ROLE=f.getROLE();

    if(ROLE == "INSPECTION" || ROLE == "ADMIN")
    {ui->acceuil->hide();
        ui->gestion_formation->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion inspection");
    }
}

void MainWindow::on_acceuil_gestion_certificat_clicked()
{
    QString ROLE=f.getROLE();

    if(ROLE == "CERTIFICAT" || ROLE == "ADMIN")
    {ui->acceuil->hide();
        ui->gestion_formation->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion certificat");
    }
}

void MainWindow::on_acceuil_gestion_formation_clicked()
{
    QString ROLE=f.getROLE();

    if(ROLE == "FORMATION" || ROLE == "ADMIN")
    {ui->acceuil->hide();
        ui->gestion_formation->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion formation");
    }
}

void MainWindow::on_gestion_formation_deconnecter_clicked()
{
    ui->gestion_formation->hide();
    ui->login->show();

}

void MainWindow::on_bt_historique_clicked()
{
    ui->gestion_formation->hide();
    ui->historique->show();
}

// Declare the modelHeader variable


void MainWindow::onComboBoxhistorique(int index)
{
    QString selectedOption = ui->afficher_historique->itemText(index);
    QString filePath;
QString modelHeader;
    if (selectedOption == "ajout") {
        filePath = "/Users/Msi/OneDrive/Bureau/ajout.txt";
        modelHeader = "AJOUT";
    } else if (selectedOption == "modification") {
        filePath = "/Users/Msi/OneDrive/Bureau/modification.txt";
        modelHeader = "MODIFICATION";
    } else if (selectedOption == "suppression") {
        filePath = "/Users/Msi/OneDrive/Bureau/suppression.txt";
        modelHeader = "SUPPRESSION";
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();
        file.close();

        if (fileContent.isEmpty()) {
            QMessageBox::information(this, "Empty", "The file is empty.");
        } else {
            QStringList rows = fileContent.split("\n");
            QStandardItemModel *model = new QStandardItemModel(this);
            model->setColumnCount(1);

            for (const QString &row : rows) {
                QStandardItem *item = new QStandardItem(row);
                model->appendRow(item);
            }

            model->setHeaderData(0, Qt::Horizontal, QObject::tr(modelHeader.toUtf8().constData()));

            ui->tableView_historique->setModel(model);
            ui->tableView_historique->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            ui->tableView_historique->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->historique->hide();
    ui->gestion_formation->show();
}
void MainWindow::Notification()
{
    ui->notif_bar->clear();
    QSqlQuery query;
    query.exec("SELECT DATE_DE_DEBUT, FORMATEUR FROM formation WHERE DATE_DE_DEBUT >= CURRENT_DATE ORDER BY DATE_DE_DEBUT ASC");

    QDateTime currentDateTime = QDateTime::currentDateTime();

    QDateTime closestDateTime;
    QString closestFormateur;
    QList<QDateTime> formationDateTimes;
    while (query.next()) {
        QDateTime formationDateTime = query.value(0).toDateTime();
        QString formateur = query.value(1).toString();
        if (formationDateTime.isValid() && !formateur.isEmpty()) {
            formationDateTimes.append(formationDateTime);
            if (closestDateTime.isNull() || formationDateTime < closestDateTime) {
                closestDateTime = formationDateTime;
                closestFormateur = formateur;
            }
        }
    }

    if (!formationDateTimes.isEmpty()) {
        QDate currentDate = currentDateTime.date();
        QDate closestDate = closestDateTime.date();
        int daysLeft = currentDate.daysTo(closestDate);

        QString message;
        if (daysLeft > 0) {
            message = "Il reste encore " + QString::number(daysLeft) + " jours avant la formation de " + closestFormateur;
        } else {

            message = "La formation du " +closestFormateur  + " est aujourd'hui" ;
        }

        ui->notif_bar->setText(message);
    } else {
        ui->notif_bar->setText("No upcoming formations");
    }
}
QString MainWindow::Message_Notification()
{
    QString message;

    QSqlQuery query;
    query.exec("SELECT DATE_DE_DEBUT, FORMATEUR FROM formation WHERE DATE_DE_DEBUT >= CURRENT_DATE ORDER BY DATE_DE_DEBUT ASC");

    QDateTime currentDateTime = QDateTime::currentDateTime();

    QDateTime closestDateTime;
    QString closestFormateur;
    QList<QDateTime> formationDateTimes;
    while (query.next()) {
        QDateTime formationDateTime = query.value(0).toDateTime();
        QString formateur = query.value(1).toString();
        if (formationDateTime.isValid() && !formateur.isEmpty()) {
            formationDateTimes.append(formationDateTime);
            if (closestDateTime.isNull() || formationDateTime < closestDateTime) {
                closestDateTime = formationDateTime;
                closestFormateur = formateur;
            }
        }
    }

    if (!formationDateTimes.isEmpty()) {
        QDate currentDate = currentDateTime.date();
        QDate closestDate = closestDateTime.date();
        int daysLeft = currentDate.daysTo(closestDate);

        if (daysLeft > 0) {
            message = "Il reste encore " + QString::number(daysLeft) + " jours avant la formation de " + closestFormateur;
        } else {
            message = "La formation de " + closestFormateur + " est aujourd'hui.";
        }
    } else {
        message = "No upcoming formations";
    }

    return message;
}


void MainWindow::on_creer_return_clicked()
{
    ui->creer->hide();
    ui->login->show();
}


    void MainWindow::on_notification_system()
    {
        // Show a message box as a notification
       // QMessageBox::information(this, "Notification", "Button pressed!");

QString message = Message_Notification();
        // Send a Windows notification
        NOTIFYICONDATA nid;
        ZeroMemory(&nid, sizeof(NOTIFYICONDATA));

        nid.cbSize = sizeof(NOTIFYICONDATA);
        nid.hWnd = reinterpret_cast<HWND>(this->winId());
        nid.uID = 1;  // Unique ID for the notification icon
        nid.uFlags = NIF_INFO;
        nid.dwInfoFlags = NIIF_INFO;
        nid.uTimeout = 3000;  // Display time in milliseconds

        wcscpy_s(nid.szInfoTitle, L"Notification"); 
        wcscpy_s(nid.szInfo, message.toStdWString().c_str());

        Shell_NotifyIcon(NIM_ADD, &nid);
        Shell_NotifyIcon(NIM_DELETE, &nid);
    }


void MainWindow::on_QUITTER_clicked()
{
    close();
}

void MainWindow::on_FULLSCREEN_clicked()
{
    showFullScreen();
}



void MainWindow::on_yt_clicked()
{
    QUrl youtubeUrl("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    QDesktopServices::openUrl(youtubeUrl);
}
