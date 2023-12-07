#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QPushButton>
#include <QMessageBox>
#include <QRegExp>
#include <QSqlQuery>
#include <QSqlError>
#include <QtGui>
#include <QtSql>
#include <QtPrintSupport>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>
#include <QMouseEvent>
#include <QDate>
#include <QTime>
#include <cstdlib>
#include <QFileDialog>
#include <QPixmap>
#include <QTimer>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //connect(ui->pushButtonOpenArduino, SIGNAL(clicked()), this, SLOT(openArduino()));
    ui->line_image->hide();
    connect(ui->pushButtonOpenImage, &QPushButton::clicked, this, &MainWindow::openImageDialog);

    //connect arduino
        arduino a;
        int ret=a.connect_arduino();
            switch(ret)
            {case(0):qDebug()<<"arduino est disponible et connecter sur :"<<a.getarduino_port_name();
                break;
             case(1):qDebug()<<"arduino est disponible mais il n est pas connecter sur:"<<a.getarduino_port_name();
                break;
             case(-1):qDebug()<<"arduino n est pas disponible";
            }
    QIntValidator *intValidator = new QIntValidator(0, 9999, this);
           ui->id->setValidator(intValidator);
           QIntValidator *intValidator2 = new QIntValidator(0, 99999999, this);
           ui->num->setValidator(intValidator2);
    connect(ui->recherch, &QLineEdit::textChanged, this, &MainWindow::on_texte_recherche_textChanged);
    ui->idsup->clear();

                QSqlQuery query;
                            query.exec("SELECT id FROM GESTION_EMPLOYÉ");

                            // Populate the combobox with data from the database
                            while (query.next()) {
                                int idd = query.value(0).toInt();
                                ui->idsup->addItem(QString::number(idd));
                            }
    ui->ajout->hide();
    ui->base->show();
    ui->label_32->hide();
    float s0, s1;
    s0 = countType("Homme");
    s1 = countType("Femme");


    float stat = s0 + s1 ;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

    QString ch1 = QString("Homme %1%").arg(static_cast<int>(x));
    QString ch2 = QString("Femme %1%").arg(static_cast<int>(y));


        QPieSeries *series=new QPieSeries();
        series->setHoleSize(0.35);

        QPieSlice *slice= series->append(ch1,x);
        slice->setLabelVisible();
        slice->setLabelColor(QColor("#FFFFFF"));
        slice->setBrush(QColor(84, 16, 149, 1));
        QPieSlice *slice1= series->append(ch2,y);
        slice1->setLabelVisible();
        slice1->setLabelColor(QColor("#FFFFFF"));
        slice1->setBrush(QColor(189, 76, 224, 1));

        QChart *chart=new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QBrush backgroundBrush(QColor(187,93,87,0));
        chart->setBackgroundBrush(backgroundBrush);
        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setFixedSize(ui->label_32->size());
        chartview->setParent(ui->label_32);
        ui->label_32->setStyleSheet("background:transparent; color:white; ");
        ui->label_32->show();

        ui->table->setStyleSheet("QTableView{color: white; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                                           "width: 484px;"
                                                           "height: 60px;"
                                                           "padding: 20px 16px;"
                                                           "spacing: 24px;"
                                                           "}"
                                                            " color: white; background-color: rgba(0, 0, 0, 0.5); ");

        ui->image->setStyleSheet("font-size: 15px;"
                               "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 5px 2px;"
                                    "padding-left: 15px;"
                                   "font-family:Arial;");


    idsup = ui->idsup;
    idsup->setStyleSheet("font-size: 15px;"
                           "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                               "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                               "width: 484px;"
                               "height: 60px;"
                               "padding: 5px 2px;"
                                "padding-left: 15px;"
                               "font-family:Arial;");

    id = ui->id;
    id->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    nom = ui->nom;
    nom->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    prenom = ui->prenom;
    prenom->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    date = ui->date;
    date->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    sexe = ui->sexe;
    sexe->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    ui->sexe->addItem("Homme");
    ui->sexe->addItem("Femme");
    email = ui->email;
    email->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    num = ui->num;
    num->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    poste = ui->poste;
    poste->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    ui->poste->addItem("Environnemental");
    ui->poste->addItem("Externe");
    ui->poste->addItem("Qualite");
    ui->poste->addItem("Conformite");

    date1 = ui->date1;
    date1->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    date2 = ui->date2;
    date2->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"
                           "font-family:Arial;");
    ui->table->setModel(E.afficher());
    recherch=ui->recherch;
    recherch->setStyleSheet("font-size: 15px;"
                               "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 5px 2px;"
                                    "padding-left: 15px;"
                                   "font-family:Arial;");
    ui->rechercher->installEventFilter(this);
    ui->recherch->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}



/*void MainWindow::openArduino() {
    // Specify the path to the Arduino executable
    QString arduinoPath = "C:/Arduino/arduino.exe";
      // Change this to the actual path on your system
    if (QFile(arduinoPath).exists()) {

    // Create the Arduino process
    QProcess *arduinoProcess = new QProcess(this);

    // Set the working directory
    arduinoProcess->setWorkingDirectory(QCoreApplication::applicationDirPath());

    // Start the Arduino process
    arduinoProcess->start(arduinoPath);

    // Check if the process started successfully
    if (arduinoProcess->waitForStarted()) {
        qDebug() << "Arduino process started successfully";
    } else {
        qDebug() << "Failed to start Arduino process. Error: " << arduinoProcess->errorString();
    }

    // Connect to the finished signal to handle process completion
    connect(arduinoProcess, SIGNAL(finished(int)), this, SLOT(arduinoProcessFinished(int)));
    } else {
        qDebug() << "Arduino executable not found at the specified path.";
    }
}

void MainWindow::arduinoProcessFinished(int exitCode) {
    // Handle process completion if needed
    qDebug() << "Arduino process finished with exit code: " << exitCode;
}*/


void MainWindow::openImageDialog() {
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.bmp *.gif)");

    if (!imagePath.isEmpty()) {
        // Load the image using QPixmap
        QPixmap image(imagePath);

        // Update the QLabel with the image
        ui->image->setPixmap(image.scaled(ui->image->size(), Qt::KeepAspectRatio));
        ui->line_image->setText(imagePath);
        ui->line_image->hide();
    }
}


void MainWindow::updateTime() {
    QDate selectedDate = ui->calendarWidget->selectedDate();

    // Check if the selected day is Saturday or Sunday (weekend)
        if (selectedDate.dayOfWeek() == Qt::Saturday || selectedDate.dayOfWeek() == Qt::Sunday) {
            ui->label_12->setText("It is a weekend. No work scheduled.");
            return;}
    // Use qrand() to generate random start time between 8am and 11am (inclusive)
    int randomStartHour = qrand() % 4 + 8;
    QTime startTime(randomStartHour, 0);

    // Calculate finish time (6 hours later) and ensure it is within 8am to 5pm
    QTime finishTime = startTime.addSecs(6 * 3600);
    if (finishTime > QTime(17, 0)) {
        // Adjust finish time to be within the valid range
        finishTime = QTime(17, 0);
        startTime = finishTime.addSecs(-6 * 3600);
    }

    QDateTime startDateTime(selectedDate, startTime);
    QDateTime finishDateTime(selectedDate, finishTime);

    ui->label_12->setText("Start Time: " + startDateTime.toString("hh:mm AP") +
                       "\nFinish Time: " + finishDateTime.toString("hh:mm AP"));

}

void MainWindow::saveEmployeeTime(const QDateTime &startTime, const QDateTime &finishTime) {
    QSqlQuery query;

    int mid = ui->idsup->currentText().toInt();
    query.prepare("UPDATE GESTION_EMPLOYÉ SET start_time = :start_time, finish_time = :finish_time WHERE id = :id;");
    query.bindValue(":id", mid);
    query.bindValue(":start_time", startTime.toString("dd-MM-yyyy hh:mm:ss"));
    query.bindValue(":finish_time", finishTime.toString("dd-MM-yyyy hh:mm:ss"));

    if (query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Updated\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Not updated\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
        Employe E1;
        E1.setid(ui->idsup->currentText().toInt());
        bool test=E1.supprimer(E1.getid());
        if(test)
        {
            ui->idsup->clear();
                        QSqlQuery query;
                                    query.exec("SELECT id FROM GESTION_EMPLOYÉ");

                                    // Populate the combobox with data from the database
                                    while (query.next()) {
                                        int idd = query.value(0).toInt();
                                        ui->idsup->addItem(QString::number(idd));
                                    }
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectuée.\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        ui->table->setModel(E.afficher());
}

/*void MainWindow::on_refresh_clicked()
{
    ui->table->setModel(E.afficher());
}*/

void MainWindow::on_openajoutButton_clicked()
{
    ui->ajout->show();
    ui->base->hide();
}

void MainWindow::on_eng_clicked()
{
        bool isIdValid = false;
        int id = ui->id->text().toInt(&isIdValid);
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        QString email=ui->email->text();
        QString numero_telephone=ui->num->text();
        QDate date_naissance=ui->date->date();
        QString poste=ui->poste->currentText();
        QString sexe=ui->sexe->currentText();
        QDate date_embauche=ui->date1->date();
        QDate fin_contrat=ui->date2->date();
        QString image=ui->line_image->text();
        QRegExp regex2("^[A-Za-z]{2,30}");
        QRegExp regex3("^[A-Za-z0-9]{3,30}$");
        QRegExp regex4("^[0-9]{8}$");
        QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

        if (isIdValid)
        {
            if(nom.contains(regex2) && prenom.contains(regex2) && email.contains(emailRegex) && numero_telephone.contains(regex4))
            {
                Employe E(id,nom,prenom,date_naissance,poste,sexe,email,numero_telephone,date_embauche,fin_contrat,image);
                bool test=E.ajouter();
                if(test)
                {
                    ui->idsup->clear();
                                QSqlQuery query;
                                            query.exec("SELECT id FROM GESTION_EMPLOYÉ");

                                            // Populate the combobox with data from the database
                                            while (query.next()) {
                                                int idd = query.value(0).toInt();
                                                ui->idsup->addItem(QString::number(idd));
                                            }
                    ui->table->setModel(E.afficher());
                    QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("Ajout effectué\nClick Cancel to exit."),QMessageBox::Cancel);
                }
                else {
                    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("Ajout non effectué\nClick Cancel to exit."),QMessageBox::Cancel);
                }
            }
            else
            {
                if(!nom.contains(regex2))
                {
                    QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Nom doit contenir entre 2 et 30 lettres.\nClick Cancel to exit."),QMessageBox::Cancel);
                }
                else
                {
                    if(!prenom.contains(regex2))
                    {
                        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Prénom doit contenir entre 2 et 30 lettres.\nClick Cancel to exit."),QMessageBox::Cancel);

                    }
                    else
                    {
                        if(!email.contains(emailRegex))
                        {
                            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Email doit etre sous la forme : exemple@exemple.com.\nClick Cancel to exit."),QMessageBox::Cancel);

                        }
                        else
                        {
                            if(!numero_telephone.contains(regex4))
                            {
                                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Numéro de téléphone doit contenir 8 chiffres.\nClick Cancel to exit."),QMessageBox::Cancel);

                            }
                        }
                    }
                }
            }

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Id doit contenir au maximum 3 chiffres.\nClick Cancel to exit."),QMessageBox::Cancel);

        }

}

void MainWindow::on_modifier_clicked()
{
        ui->ajout->show();
        ui->base->hide();
        int mid =ui->idsup->currentText().toInt();
        QSqlQuery query;
        query.prepare("SELECT * FROM GESTION_EMPLOYÉ WHERE id = :id");
        query.bindValue(":id", mid);

                        if (query.exec() && query.next()) {

                              QString mnom=query.value("nom").toString();
                              QString mprenom = query.value("prénom").toString();
                              QDate mdate = query.value("date_naissance").toDate();
                              QString memail = query.value("email").toString();
                              int mnumero = query.value("numéro_telephone").toInt();
                              QString msexe = query.value("sexe").toString();
                              QString mposte = query.value("poste").toString();
                              QDate mdate1 = query.value("date_embauche").toDate();
                              QDate mdate2 = query.value("fin_contrat").toDate();
                              QString mimage=query.value("image").toString();

                              ui->id->setText(QString::number(mid));
                              ui->id->setReadOnly(true);
                              ui->nom->setText(mnom);
                              ui->prenom->setText(mprenom);
                              ui->date->setDate(mdate);
                              ui->email->setText(memail);
                              ui->num->setText(QString::number(mnumero));
                              ui->sexe->setCurrentText(msexe);
                              ui->poste->setCurrentText(mposte);
                              ui->date1->setDate(mdate1);
                              ui->date2->setDate(mdate2);
                              ui->image->setText(mimage);
                              QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("Modification effectué\nClick Cancel to exit."),QMessageBox::Cancel);


                          }

}


void MainWindow::on_return_2_clicked()
{

    ui->base->show();
    ui->ajout->hide();

}

void MainWindow::on_trier_clicked()
{
    QSqlQuery query;
        QSqlQueryModel* model = new QSqlQueryModel();

        query.prepare("SELECT id, nom, prénom,poste FROM GESTION_EMPLOYÉ ORDER BY poste ASC ");


        if (query.exec()) {
            model->setQuery(query);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom"));
            model->setHeaderData(3, Qt::Horizontal,QObject::tr("Poste"));
            ui->table->setModel(model);
        }
}

void MainWindow::on_texte_recherche_textChanged(const QString &text)
{
    QSqlQueryModel* searchModel = new QSqlQueryModel();
    searchModel->setQuery(QString("SELECT id,nom,prénom,poste FROM GESTION_EMPLOYÉ WHERE id LIKE '%1%'").arg(text));

    if (searchModel->rowCount() > 0) {
        // If the search result is not empty
        ui->table->setModel(searchModel);
}
        if (searchModel->rowCount() == 0) {
            // If the search result is not empty
            ui->table->setModel(searchModel);
}
        // Adjust the header view as needed
        QHeaderView* headerView = ui->table->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);


}

void MainWindow::on_pdf_clicked()
{
    QString strStream;

     QTextStream out(&strStream);


                                     const int rowCount = ui->table->model()->rowCount();

                                     const int columnCount = ui->table->model()->columnCount();



                                     out <<  "<html>\n"

                                         "<head>\n"

                                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                                         <<  QString("<title>%1</title>\n").arg("strTitle")

                                         <<  "</head>\n"

                                         "<body bgcolor=#ffffff link=#5000A0>\n"



                                        //     "<align='right'> " << datefich << "</align>"

                                         "<center> <H1>Liste des employes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";



                                     // headers

                                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                                     for (int column = 0; column < columnCount; column++)

                                         if (!ui->table->isColumnHidden(column))

                                             out << QString("<th>%1</th>").arg(ui->table->model()->headerData(column, Qt::Horizontal).toString());

                                     out << "</tr></thead>\n";



                                     // data table

                                     for (int row = 0; row < rowCount; row++) {

                                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                                         for (int column = 0; column < columnCount; column++) {

                                             if (!ui->table->isColumnHidden(column)) {

                                                 QString data = ui->table->model()->data(ui->table->model()->index(row, column)).toString().simplified();

                                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                                             }

                                         }

                                         out << "</tr>\n";

                                     }

                                     out <<  "</table> </center>\n"

                                         "</body>\n"

                                         "</html>\n";



                               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

                                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }



                                QPrinter printer (QPrinter::PrinterResolution);

                                 printer.setOutputFormat(QPrinter::PdfFormat);

                                printer.setPaperSize(QPrinter::A4);

                               printer.setOutputFileName(fileName);



                                QTextDocument doc;

                                 doc.setHtml(strStream);

                                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number

                                 doc.print(&printer);
}

int MainWindow::countType(const QString& sexe)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GESTION_EMPLOYÉ WHERE sexe = :sexe");
    query.bindValue(":sexe", sexe);

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

    float s0, s1;
    s0 = countType("Homme");
    s1 = countType("Femme");


    float stat = s0 + s1 ;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

    QString ch1 = QString("Homme %1%").arg(static_cast<int>(x));
    QString ch2 = QString("Femme %1%").arg(static_cast<int>(y));



        QPieSeries *series=new QPieSeries();
        series->setHoleSize(0.35);

        QPieSlice *slice= series->append(ch1,x);
        slice->setLabelVisible();
        slice->setLabelColor(QColor("#FFFFFF"));
        slice->setBrush(QColor(84, 16, 149, 1));
        QPieSlice *slice1= series->append(ch2,y);
        slice1->setLabelVisible();
        slice1->setLabelColor(QColor("#FFFFFF"));
        slice1->setBrush(QColor(189, 76, 224, 1));

        QChart *chart=new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QBrush backgroundBrush(QColor(187,93,87,0));
        chart->setBackgroundBrush(backgroundBrush);


        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setFixedSize(ui->label_32->size());
        chartview->setParent(ui->label_32);
        chartview->setStyleSheet("QToolTip { color: white; }");

        ui->label_32->setStyleSheet("background:transparent; color:white; ");
        ui->label_32->show();

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->rechercher) {
        if (event->type() == QEvent::Enter) {
            ui->recherch->setVisible(true); // Show the lineEdit on mouse enter
        } else if (event->type() == QEvent::Leave) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

            // Check if the cursor is not over the label or the lineEdit
            if (!ui->rechercher->rect().contains(mouseEvent->pos()) &&
                !ui->recherch->rect().contains(ui->recherch->mapFromGlobal(mouseEvent->globalPos()))) {
                ui->recherch->setVisible(false); // Hide the lineEdit when the cursor leaves both the label and lineEdit
            }
    }
}
    // Call the base class implementation
    return QMainWindow::eventFilter(obj, event);
}

/*void MainWindow::on_rechercher_mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ui->recherch->setVisible(true); // Show the lineEdit on mouse move
}

void MainWindow::on_rechercher_mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    ui->recherch->setFocus(); // Set focus on the lineEdit on mouse release
}*/


void MainWindow::on_chatt_clicked()
{
    ui->base->hide();
    afficherchat();
    ui->chat->show();
}

void MainWindow::on_return_3_clicked()
{
    ui->chat->hide();
    ui->base->show();
}

void MainWindow::on_temps_clicked()
{
    ui->base->hide();
    ui->tempss->show();
}


void MainWindow::on_return_4_clicked()
{
    ui->tempss->hide();
    ui->base->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->base->hide();
    ui->tempss->show();

}

void MainWindow::afficherchat()
{
    QString filePath;
    filePath = "C:/Users/MSI/OneDrive/Desktop/chat.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();
        file.close();

        if (fileContent.isEmpty()) {
            QMessageBox::information(this, "Empty", "The file is empty.");
        } else {
            // Set the file content directly to the QTextBrowser named tablechat
            ui->tablechat->setPlainText(fileContent);
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
    }
}


void MainWindow::on_sendmsg_editingFinished()
{
    QString msg=ui->sendmsg->text();
    // Write to the "supprimer" file
                        QFile file("C:/Users/MSI/OneDrive/Desktop/chat.txt");
                        if (file.open(QIODevice::Append | QIODevice::Text)) {
                            QTextStream stream(&file);
                            stream << msg << "\n" << QDateTime::currentDateTime().toString() << endl;
                            file.close();

                        }
                        afficherchat();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    Employe e;
    int dayofweek = date.dayOfWeek();

    if (dayofweek == 1)
    {
        ui->tableView3->setModel(e.afficher1());
        ui->tableView3->show();
        ui->labelNoEmployees->hide(); // Hide the label when employees are present
    }
    else if (dayofweek == 2)
    {
        ui->tableView3->setModel(e.afficher2());
        ui->tableView3->show();
        ui->labelNoEmployees->hide();
    }
    else if (dayofweek == 3)
    {
        ui->tableView3->setModel(e.afficher3());
        ui->tableView3->show();
        ui->labelNoEmployees->hide();
    }
    else if (dayofweek == 4)
    {
        ui->tableView3->setModel(e.afficher4());
        ui->tableView3->show();
        ui->labelNoEmployees->hide();
    }
    else if (dayofweek == 5)
    {
        ui->tableView3->setModel(e.afficher5());
        ui->tableView3->show();
        ui->labelNoEmployees->hide();
    }
    else if (dayofweek == 6 || dayofweek == 7)
    {
        // Display the label and hide the table view
        ui->labelNoEmployees->setText("No employees work on this day.");
        ui->labelNoEmployees->show();
        ui->tableView3->hide();
    }
    else
    {
        // Handle other days as needed
        ui->tableView3->show();
        ui->labelNoEmployees->hide();
    }
}


