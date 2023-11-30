#include "mainwindow.h"
#include "notepad.h"
#include "ui_mainwindow.h"
#include "sms.h"
#include "inspection.h"
#include "openexcel.h"
#include <QDebug>
#include<QPieSeries>
#include<QChartView>
#include<QChart>
#include<QApplication>
#include<QStandardItemModel>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>

using namespace QtCharts;
QString twilio_phone_number = "+12565677501"; //numero from where you get the sms

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //notepad = new Notepad(ui);
        arduino a;
        int ret=a.connect_arduino();
            switch(ret)
            {case(0):qDebug()<<"arduino est disponible et connecter sur :"<<a.getarduino_port_name();
                break;
             case(1):qDebug()<<"arduino est disponible mais il n est pas connecter sur:"<<a.getarduino_port_name();
                break;
             case(-1):qDebug()<<"arduino n est pas disponible";
            }


    ui->label_32->hide();
    //ui->login->hide();
    ui->groupBox_Notepad->hide();
    STATISTIQUE();
    ui->groupBox_sms->hide();
    ui->Gestion_Inspection_ajouter->hide();
    ui->groupBox_Modifier->hide();
    ui->gestion_inspection->show();
    ui->login_email->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
    ui->login_mdp->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
    ui->login_mdp->setPlaceholderText("Entrez votre mot de passe");
    ui->login_email->setPlaceholderText("Entrez votre email");

   // ui->label_test->setStyleSheet("background:blue");
   // QString styleSheet = QString("background: #%1;").arg("47A1FA");
    //ui->label_test->setStyleSheet(styleSheet);
    //ui->pushButton_entrer->setStyleSheet("border:2px,;font-size:20px;");
    Inspection i;
  ui->list->setModel(i.afficher());
  ui->G_Inspection_AJOUTER->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
  ui->G_Inspection_NOTEPAD->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
  ui->return_sms->setStyleSheet("background:transparent");
  ui->G_Inspection_SUPPRIMER->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
   ui->comboBox_id->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

  ui->pushButton_return_notepad->setStyleSheet("background:transparent;border:none");
  ui->G_Inspection_MODIFIER->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

 ui->pushButton_enregistre_notepad->setStyleSheet("background:transparent");
  ui->G_Inspection_SMS->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

  ui->G_Inspection_TRI->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

  //ui->G_Inspection_STATISTIQUE->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
 // ui->G_Inspection_STATISTIQUE->move(400,890);
 // ui->G_Inspection_PDF->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
 // ui->G_Inspection_PDF->move(950,840);

  QPixmap pic_blasa(":/images/List.png");
  blasa=new QLabel(ui->lineEdit_recherche);
  blasa->setPixmap(pic_blasa);
  ui->lineEdit_recherche->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
 ui->lineEdit_recherche->setPlaceholderText("Entrez votre identifant");
  ui->lineEdit_recherche->setValidator( new QIntValidator(100, 999999, this));
  ui->G_Inspection_REFRESH->setStyleSheet("background:transparent;border:none");
  ui-> list->setStyleSheet("color: #FFF;"
                           " border-radius: 20px;"
                           "border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "height: 800px;"
                           "padding: 20px 16px;"
                           "align-items: center;"
                           "spacing: 40px;"
                           "flex: 0;"
                           "font-size: 20px;"
                           "QHeaderView::section {"
                           "color: white;"  // Remplacez "white" par la couleur que vous souhaitez utiliser
                                               "}");
 ui-> list->setStyleSheet("QTableView{color: #DCBFFF; border-radius: 20px; border: 1px solid rgba(255, 0, 0, 0.);"
                                                 "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                                 "display: flex;"
                                                 "width: 484px;"
                                                 "height: 60px;"
                                                 "padding: 20px 16px;"
                                                 "align-items: center;"
                                                 "spacing: 24px;"
                                                 "flex: 0;}"
                                                 " color: white; background-color: rgba(0, 0, 0, 0.5); ");


  setFixedSize(1920,1080);

ui->return_ajouter->setStyleSheet("background:transparent;border:none");
QSqlQuery query;
                  ui->comboBox_id->clear();
                      query.exec("SELECT IDIN FROM INSPECTION");
                      while (query.next()) {
                          int id = query.value(0).toInt();

 ui->comboBox_id->addItem(QString::number(id));}
                        //signal
 connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_recherche_textChanged);
 //connect(ui->label_32, &QLabel::linkActivated, this, &MainWindow::STATISTIQUE);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_G_Inspection_AJOUTER_clicked()
{
    ui->Gestion_Inspection_ajouter->show();
    ui->gestion_inspection->hide();
}

void MainWindow::on_return_ajouter_clicked()
{
    ui->Gestion_Inspection_ajouter->hide();
    ui->gestion_inspection->show();
}

void MainWindow::on_ajouter_enregistrer_clicked()
{

    bool test=false;
    int IDIN = ui->lineEdit_idin->text().toInt();
    QDate date =ui->dateEdit->date();
     float frais = ui->lineEditfrais->text().toFloat();
     QString methode = ui->comboBox_Methode->currentText();//methode
     QString etat = ui->comboBox_Etat->currentText();//etat
     QString type = ui->comboBox_Type->currentText();//type
     Inspection i(IDIN,date,frais,methode,etat,type);
     bool test1=i.function_search(IDIN);
     if(!test1){


     test=i.ajouter();
     if(test)
     { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout Réussi.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
        ui->list->setModel(i.afficher());
       // remplir_combobox(id_a_supprimee);
     }
     else
     {
             QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Échec de l'Ajout.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
        }}
     else QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("id deja existe \n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);


}


void MainWindow::on_G_Inspection_SUPPRIMER_clicked()
{
    Inspection I1;
        I1.setIDIN(ui->comboBox_id->currentText().toInt());
        bool test = I1.supprimer(I1.getIDIN());
        if(test)
        {
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression reussi.\n""Click cancel to exit."),QMessageBox::Cancel);
            ui->list->setModel(I1.afficher());
            QSqlQuery query;
                              ui->comboBox_id->clear();
                                  query.exec("SELECT IDIN FROM INSPECTION");
                                  while (query.next()) {
                                      int id = query.value(0).toInt();
                                      ui->comboBox_id->addItem(QString::number(id));}

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Echec du Suppression .\n""Click cancel to exit."),QMessageBox::Cancel);
        }

}


void MainWindow::on_G_Inspection_TRI_clicked()
{
    QSqlQueryModel * model_sort=new QSqlQueryModel;
    model_sort->setQuery(" SELECT * FROM INSPECTION ORDER BY IDIN ASC");
    ui->list->setModel(model_sort);

      QHeaderView* headerView = ui->list->horizontalHeader();
      headerView->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &id)
{


             QSqlQueryModel* searchModel = new QSqlQueryModel();
             searchModel->setQuery("SELECT * FROM INSPECTION WHERE IDIN LIKE '%" + id + "%'");

             if (searchModel->rowCount() > 0) {

                 ui->list->setModel(searchModel);
                 QHeaderView* headerView = ui->list->horizontalHeader();
                 headerView->setSectionResizeMode(QHeaderView::Stretch);
             } else {

                 QMessageBox::information(this, "Search Result", "Inspection does not exist.");
             }
}



void MainWindow::on_pushButton_modifier_clicked()
{
  Inspection i;
    int c=0;
        // Get the values from the UI elements
    int IDIN=ui->lineEdit_idin_m->text().toInt();
    QDate date =ui->dateEdit_m->date();
     float frais = ui->lineEditfrais_m->text().toFloat();
     QString methode = ui->comboBox_Methode_m->currentText();//methode
     QString etat = ui->comboBox_Etat_m->currentText();//etat
     QString type = ui->comboBox_Type_m->currentText();//type



    if(c==0)
    {
        // Update the record in the database

        bool test = i.modifier(IDIN,date,frais,methode,etat,type);

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification Réussi.\n""Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);


            ui->list->setModel(i.afficher());// Refresh your table view after modification
            // STATISTIQUE();
           //ui->modifier_formation->hide();
            //ui->gestion_formation->show();
        } else {
            qDebug() << IDIN <<endl ;
            QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Échec de la Modification.\n""Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }

    ui->groupBox_Modifier->hide();
    ui->gestion_inspection->show();
}

void MainWindow::on_G_Inspection_MODIFIER_clicked()
{
    // Get the selected ID from the combo box
       int selectedId = ui->comboBox_id->currentText().toInt();

       // Call the function to update the UI with the selected ID's data
       QSqlQuery query;

       // Re eve and set values for other UI elements based on the selected ID
       query.prepare("SELECT   DATE_MISSION ,FRAIT_MISSION, METHODE,ETAT,TYPE_MISSION from INSPECTION  where IDIN=:id");
       query.bindValue(":id", selectedId);

       if (query.exec() && query.next())
       {
            QDate date = query.value(0).toDate();
           QString frais = query.value(1).toString();
           QString methode = query.value(2).toString();
           QString etat = query.value(3).toString();
           QString  type= query.value(4).toString();



           // Update the UI elements with the retrieved data
           ui->lineEdit_idin_m->setText(ui->comboBox_id->currentText());
           ui->dateEdit_m->setDate(date);

           ui->lineEditfrais_m->setText(frais);
          // ui->comboBox_Methode_m->setText(methode);

           int index = ui->comboBox_Methode_m->findText(methode);
           if (index != -1) {
               ui->comboBox_Methode_m->setCurrentIndex(index);
           }

           int index2 = ui->comboBox_Etat_m->findText(etat);
           if (index2 != -1) {
               ui->comboBox_Etat_m->setCurrentIndex(index2);
           }
           int index3= ui->comboBox_Type_m->findText(type);
           if (index3 != -1) {
               ui->comboBox_Type_m->setCurrentIndex(index3);
           }

       // Show the appropriate UI elements
           ui->Gestion_Inspection_ajouter->hide();
           ui->gestion_inspection->hide();
           ui->groupBox_Modifier->show();

}
}




void MainWindow::on_pushButton_pdf_clicked()
{
    // Associez le modèle à votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->list->model());

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
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/Beats SQA/Documents", "Fichiers PDF (*.pdf)");

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


void MainWindow::on_G_Inspection_REFRESH_clicked()
{
    Inspection i;
  ui->list->setModel(i.afficher());
  ui->label_32->show();

}

int MainWindow::countType(const QString& type)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(\"ETAT\") FROM INSPECTION WHERE \"ETAT\" = :type");
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

    int s0, s1, s2, s3,s4;

    s0 = countType("Environnemental");
    s1 = countType("Interne");
    s2 = countType("Externe");
    s3 = countType("Financier");
    s4 = countType("De Qualite");



    int stat = s0 + s1 + s2 + s3+ s4 ;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float x1 = (stat != 0) ? (s1 * 100) / stat : 0.0;
    float x2 = (stat != 0) ? (s2 * 100) / stat : 0.0;
    float x3 = (stat != 0) ? (s3 * 100) / stat : 0.0;
     float x4 = (stat != 0) ? (s4 * 100) / stat : 0.0;



    QString ch1 = QString("Environnemental %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("Interne %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("Externe %3%").arg(QString::number(x2, 'f', 2));
  QString ch4 = QString("Financier %4%").arg(QString::number(x3, 'f', 2));
   QString ch5 = QString("De Qualite %4%").arg(QString::number(x4, 'f', 2));


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

    QPieSlice *slice4= series->append(ch5,x4);
    slice4->setLabelVisible();
    slice4->setLabelColor(QColor(Qt::white));
    slice4->setBrush(QColor(Qt::white));




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
/*void MainWindow::on_G_Inspection_STATISTIQUE_clicked()
{
    // Create a bar series
       QtCharts::QBarSeries *series = new QtCharts::QBarSeries(this);

       // Create bar sets and add data
       QtCharts::QBarSet *set1 = new QtCharts::QBarSet("JANV");
       *set1 << 30 ;
       QtCharts::QBarSet *set2 = new QtCharts::QBarSet("FEVR");
       *set2 << 10 ;
       QtCharts::QBarSet *set3 = new QtCharts::QBarSet("MARS");
       *set3 << 10 ;
       QtCharts::QBarSet *set4 = new QtCharts::QBarSet("ARV");
       *set4 << 90 ;
       QtCharts::QBarSet *set5 = new QtCharts::QBarSet("MAI");
       *set5 << 10 ;
       QtCharts::QBarSet *set6 = new QtCharts::QBarSet("JUIN");
       *set6 << 10 ;
       QtCharts::QBarSet *set7 = new QtCharts::QBarSet("JUIL");
       *set7 << 20 ;
       QtCharts::QBarSet *set8 = new QtCharts::QBarSet("AOUT");
       *set8 << 50 ;
       QtCharts::QBarSet *set9 = new QtCharts::QBarSet("SEPT");
       *set9 << 40 ;
       QtCharts::QBarSet *set10 = new QtCharts::QBarSet("OCT");
       *set10 << 80 ;
       QtCharts::QBarSet *set11 = new QtCharts::QBarSet("NOV");
       *set11 << 60 ;
       QtCharts::QBarSet *set12 = new QtCharts::QBarSet("DEC");
       *set12 << 50 ;


       series->append(set1);
       series->append(set2);
       series->append(set3);
       series->append(set4);
       series->append(set5);
       series->append(set6);
       series->append(set7);
       series->append(set8);
       series->append(set9);
       series->append(set10);
       series->append(set11);
       series->append(set12);


       // Create a chart and set the series
       QtCharts::QChart *chart = new QtCharts::QChart();
       chart->addSeries(series);
       chart->setTitle("Statistique du nb des inspection par mois");
       chart->setGeometry(500,500,500,500);

       // Create a chart view and set the chart
       QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       QImage chartImage(chartView->size(), QImage::Format_ARGB32_Premultiplied);
           QPainter painter(&chartImage);
           chartView->render(&painter);
           painter.end();

           // Display the image in a QLabel
           QLabel label;
           label.setPixmap(QPixmap::fromImage(chartImage));
           label.show();

       // Show the chart view
       chartView->show();
}*/

void MainWindow::on_G_Inspection_SMS_clicked()
{
     ui->gestion_inspection->hide();
    ui->groupBox_sms->show();
}

void MainWindow::on_pushButton_SMS_confirme_clicked()
{
    SMS s;
                const QString msg = ui->msg->text();
               const QString recipient_phone_number = "+216"+ ui->phone->text();
              s.sendSMS(recipient_phone_number, msg);

}

void MainWindow::on_return_sms_clicked()
{
    ui->groupBox_sms->hide();
    ui->gestion_inspection->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                openexcel obj(fileName, "INSPECTION",ui->list);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "IDIN", "char(20)");
                obj.addField(1, "FRAIT_MISSION", "char(20)");
               // obj.addField(2, "ETAT", "char(20)");
                //obj.addField(3, "TYPE_MISSION", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_pushButton_return_notepad_clicked()
{
    ui->groupBox_Notepad->hide();
    ui->gestion_inspection->show();

}

void MainWindow::on_G_Inspection_NOTEPAD_clicked()
{
    ui->groupBox_Notepad->show();
    ui->gestion_inspection->hide();

    QSqlQuery query;

    ui->comboBox_notepad->clear();
        query.exec("SELECT IDIN FROM INSPECTION");
        while (query.next()) {
            int id = query.value(0).toInt();
            ui->comboBox_notepad->addItem(QString::number(id));}
}

/**void MainWindow::on_pushButton_enregistre_notepad_clicked()
{

    QFile file("C:/Users/Beats SQA/Desktop/notepad.txt");
                    if (file.open(QIODevice::Append | QIODevice::Text)) {
                        QTextStream stream(&file);
                        stream << "ID modifier: " << msg << ", Time: " << QDateTime::currentDateTime().toString() << endl;
                        file.close();
                    }


}*

void MainWindow::on_Notepad_ecrire_clicked()
{
    ui->textEdit->show();
}

void MainWindow::on_NOtepad_afficher_clicked()
{
ui->textEdit->hide();

    QString filePath = "C:/Users/Beats SQA/Desktop/notepad.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();
        file.close();

        if (fileContent.isEmpty()) {
            QMessageBox::information(this, "Empty", "The file is empty.");
        } else {
            ui->textBrowser->setText(fileContent);
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
    }
      ui->textBrowser->show();
}


void MainWindow::on_pushButton_enregistre_notepad_clicked()
{
    QString msg=ui->textEdit->toPlainText();
    QFile file("C:/Users/Beats SQA/Desktop/notepad.txt");
                    if (file.open(QIODevice::Append | QIODevice::Text)) {
                        QTextStream stream(&file);
                        stream << " " << msg << ", \n Time: " << QDateTime::currentDateTime().toString() << endl;
                        file.close();
                    }
      ui->textEdit->clear();
}*/



void MainWindow::on_pushButton_annuler_m_clicked()
{
    ui->groupBox_Modifier->hide();
    ui->gestion_inspection->show();
}



/*void MainWindow::on_pushButton_enregistre_notepad_clicked()
{
    Notepad n;
    // Opens a dialog for saving a file
        QString fileName = QFileDialog::getSaveFileName(this, "Save as");

        // An object for reading and writing files
        QFile file(fileName);

        // Try to open a file with write only options
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        // Store the currentFile name
        n.currentFile = fileName;

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Interface for writing text
        QTextStream out(&file);

        // Copy text in the textEdit widget and convert to plain text
        QString text = ui->textEdit->toPlainText();

        // Output to file
        out << text;

        // Close the file
        file.close();
}*/



/*void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{

}*/
bool MainWindow::modifier_presence_employe(int id,QString PRECENSE)
{
    QSqlQuery query;


    query.prepare("UPDATE INSPECTION SET TYPE_MISSION=:ETAT where IDIN=:IDIN");
    query.bindValue(":IDIN", id);
    query.bindValue(":ETAT",PRECENSE);



      if (query.exec()) {
          // Commit the transaction
          QSqlDatabase::database().commit();
          return true;
      } else {
          // Rollback the transaction in case of an error
          QSqlDatabase::database().rollback();
          return false;
      }
}

void MainWindow::on_G_Inspection_test_clicked()
{
    arduino a;
       int x=1;
       bool test;
       QString strData = "1";
       QByteArray data = strData.toUtf8();
       x=a.write_to_arduino(data);
       if(x==0)
       {

   test=modifier_presence_employe(3455," Acomplie");
   if(test)
      {
       QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr(" Acomplie"), QMessageBox::Cancel);
   }

       }
}
bool MainWindow::modifier_presence_login(QString admin,QString PRECENSE)
{
    QSqlQuery query;


    query.prepare("UPDATE EMPLOYE SET PRESENCE=:PRECENSE where EMAIL=:admin");
    query.bindValue(":PRECENSE",PRECENSE);
    query.bindValue(":admin",admin);


      if (query.exec()) {
          // Commit the transaction
          QSqlDatabase::database().commit();
          return true;
      } else {
          // Rollback the transaction in case of an error
          QSqlDatabase::database().rollback();
          return false;
      }
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


                ui->login_email->clear();
                ui->login_mdp->clear();
                ui->login->hide();
                ui->gestion_inspection->show();
            } else {
                // Password is incorrect
                QMessageBox::critical(this, "Error", "Incorrect password");
            }
        } else {
            // User record not found
            QMessageBox::critical(this, "Error", "Incorrect email");
        }

}

void MainWindow::on_pushButton_TT_clicked()
{
    bool test;
    int x;

        x=A.write_to_arduino("1");
        if (x==1) qDebug()<<x<<endl;
        data=A.read_from_arduino();
        qDebug()<<"data="<< data;
        if(data=="0")
        {
            ui->login_email->setText("ouiem.zakhama@esprit.tn");
            ui->login_mdp->setText("Zakhama123");
            test=modifier_presence_login("ouiem.zakhama@esprit.tn","PRESENT");
                if(test)
                   {
                    QMessageBox msgBox(QMessageBox::Information, QObject::tr("Empreinte avec Succés"), QObject::tr("Empreinte Match \nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
                    QString styleSheet = "QMessageBox {"
                        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                        "border: 2px outset grey;"
                        "}"
                        "QMessageBox QPushButton {"
                        "color: rgba(52,90,105,100%);"
                        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                        "border-style: solid;"
                        "border: 2px solid transparent;"
                        "border-radius: 5px;"
                        "padding: 1px;"
                        "}"
                        "QMessageBox QPushButton:hover {"
                        "color: #B200ED ;"
                        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                        "border-style: solid;"
                        "border: 2px solid transparent;"
                        "border-radius: 5px;"
                        "padding: 1px;"
                        "}";

                    msgBox.setStyleSheet(styleSheet);
                    msgBox.exec();
                    //on_pushButton_3_clicked();

                    }

                }
        else
        {
            QMessageBox msgBox(QMessageBox::Warning, QObject::tr(""), QObject::tr("Ne bougez pas votre doit!!!\n."), QMessageBox::Ok);
            QString styleSheet = "QMessageBox {"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                "border: 2px outset grey;"
                "}"
                "QMessageBox QPushButton {"
                "color: rgba(52,90,105,100%);"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 90%), stop:1 rgba(132,183,164,90%));"
                "border-style: solid;"
                "border: 2px solid transparent;"
                "border-radius: 5px;"
                "padding: 1px;"
                "}"
                "QMessageBox QPushButton:hover {"
                "color: #B200ED ;"
                "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(245, 245, 220, 70%));"
                "border-style: solid;"
                "border: 2px solid transparent;"
                "border-radius: 5px;"
                "padding: 1px;"
                "}";

            msgBox.setStyleSheet(styleSheet);
            msgBox.exec();
        }
}




void MainWindow::on_login_hide_clicked()
{
    ui->login_hide->hide();
    ui->login_show->show();
    ui->login_mdp->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_login_show_clicked()
{
    ui->login_hide->show();
    ui->login_show->hide();
   ui->login_mdp->setEchoMode(QLineEdit::Normal);

}

