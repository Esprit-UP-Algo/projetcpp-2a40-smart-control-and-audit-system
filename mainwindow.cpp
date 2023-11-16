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
#include "arduino.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

                                                           "display: flex;"
                                                           "width: 484px;"
                                                           "height: 60px;"
                                                           "padding: 20px 16px;"
                                                           "align-items: center;"
                                                           "spacing: 24px;"
                                                           "flex: 0;}"
                                                            " color: white; background-color: rgba(0, 0, 0, 0.5); ");
    ui->start->setStyleSheet("font-size: 20px;"
                             "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                 "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                 "display: flex;"
                                 "width: 484px;"
                                 "height: 60px;"
                                 "padding: 5px 2px;"
                                  "padding-left: 15px;"
                                 "flex: 0;"
                                 "font-family:Arial;");

    ui->finish->setStyleSheet("font-size: 20px;"
                              "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                  "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                  "display: flex;"
                                  "width: 484px;"
                                  "height: 60px;"
                                  "padding: 5px 2px;"
                                   "padding-left: 15px;"
                                  "flex: 0;"
                                  "font-family:Arial;");

    idsup = ui->idsup;
    idsup->setStyleSheet("font-size: 15px;"
                           "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                               "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                               "display: flex;"
                               "width: 484px;"
                               "height: 60px;"
                               "padding: 5px 2px;"
                                "padding-left: 15px;"
                               "flex: 0;"
                               "font-family:Arial;");

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
    ui->poste->addItem("Environnemental");
    ui->poste->addItem("Externe");
    ui->poste->addItem("Qualite");
    ui->poste->addItem("Conformite");

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
    ui->table->setModel(E.afficher());
    recherch=ui->recherch;
    recherch->setStyleSheet("font-size: 15px;"
                               "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                   "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                   "display: flex;"
                                   "width: 484px;"
                                   "height: 60px;"
                                   "padding: 5px 2px;"
                                    "padding-left: 15px;"
                                   "flex: 0;"
                                   "font-family:Arial;");
    ui->rechercher->installEventFilter(this);
    ui->recherch->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
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
        QRegExp regex2("^[A-Za-z]{2,30}");
        QRegExp regex3("^[A-Za-z0-9]{3,30}$");
        QRegExp regex4("^[0-9]{8}$");
        QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

        if (isIdValid)
        {
            if(nom.contains(regex2) && prenom.contains(regex2) && email.contains(emailRegex) && numero_telephone.contains(regex4))
            {
                Employe E(id,nom,prenom,date_naissance,poste,sexe,email,numero_telephone,date_embauche,fin_contrat);
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
    QSqlQuery query;
            query.exec("SELECT id,nom,prénom,poste FROM GESTION_EMPLOYÉ ");

            // Create a QPdfWriter to write to a PDF file
            QPdfWriter pdfWriter("GESTION_EMPLOYÉ.pdf");
            pdfWriter.setPageSize(QPageSize(QPageSize::A4));
            pdfWriter.setPageOrientation(QPageLayout::Portrait);
            pdfWriter.setPageMargins(QMarginsF(100, 100, 100, 100));

            // Create a QPainter to draw on the PDF
            QPainter painter(&pdfWriter);

            // Create a QTextDocument to format the data
            QTextDocument doc;

            // Create a QTextCursor to write to the QTextDocument
            QTextCursor cursor(&doc);

            // Create a table format with 3 columns and adjust the table and text size
            QTextTableFormat tableFormat;
            tableFormat.setAlignment(Qt::AlignLeft);
            tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
            tableFormat.setCellSpacing(0);
            tableFormat.setCellPadding(5); // Adjust cell padding for more space

            // Define the table
            QTextTable* table = cursor.insertTable(1, 4, tableFormat);

            // Set column widths and make the table larger
            table->format().setColumnWidthConstraints(QVector<QTextLength>{
                QTextLength(QTextLength::PercentageLength, 550), // Adjust the column widths
                QTextLength(QTextLength::PercentageLength, 550),
                QTextLength(QTextLength::PercentageLength, 650),
                QTextLength(QTextLength::PercentageLength, 650)
            });

            // Create a QFont with a larger size
            QFont font = doc.defaultFont();
            font.setPointSize(140); // Adjust the font size
            doc.setDefaultFont(font);

            // Populate the table with column headers
            QTextTableCell headerCell = table->cellAt(0, 0);
            headerCell.firstCursorPosition().insertText("ID");
            QTextTableCell headerCell2 = table->cellAt(0, 1);
            headerCell2.firstCursorPosition().insertText("Nom");
            QTextTableCell headerCell3 = table->cellAt(0, 2);
            headerCell3.firstCursorPosition().insertText("Prénom");
            QTextTableCell headerCell4 = table->cellAt(0, 3);
            headerCell4.firstCursorPosition().insertText("Poste");

            // Iterate over the database table rows and write them to the PDF
            int row = 1;
            while (query.next()) {
                int id = query.value(0).toInt();
                QString nom = query.value(1).toString();
                QString prenom = query.value(2).toString();
                QString poste = query.value(3).toString();

                // Add a new row to the table and populate it with data
                table->appendRows(1);
                QTextTableCell dataCell = table->cellAt(row, 0);
                dataCell.firstCursorPosition().insertText(QString::number(id));
                QTextTableCell dataCell2 = table->cellAt(row, 1);
                dataCell2.firstCursorPosition().insertText(nom);
                QTextTableCell dataCell3 = table->cellAt(row, 2);
                dataCell3.firstCursorPosition().insertText(prenom);
                QTextTableCell dataCell4 = table->cellAt(row, 3);
                dataCell4.firstCursorPosition().insertText(poste);

                row++;
            }
                  doc.drawContents(&painter);
           painter.end();

           QMessageBox::information(this, "PDF Exported", "PDF file has been created.");
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

void MainWindow::on_eng_2_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QString startTimeStr = ui->start->time().toString("hh:mm");
    QString finishTimeStr = ui->finish->time().toString("hh:mm");
    int mid = ui->idsup->currentText().toInt();
    QSqlQuery query;

    // Select the record to check if it exists
    query.prepare("SELECT * FROM GESTION_EMPLOYÉ WHERE id = :id");
    query.bindValue(":id", mid);

    if (query.exec() && query.next()) {
        // Prepare and execute the SQL query
        query.prepare("UPDATE GESTION_EMPLOYÉ SET CALENDAR = :CALENDAR, STARTK = :STARTK, FINISHK = :FINISHK WHERE ID = :ID");
        query.bindValue(":ID", mid);
        query.bindValue(":CALENDAR",selectedDate);
        query.bindValue(":STARTK", startTimeStr);
        query.bindValue(":FINISHK", finishTimeStr);

        if (query.exec()) {
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Record updated.\nClick Cancel to exit."), QMessageBox::Cancel);
        } else {
            QMessageBox::warning(nullptr, QObject::tr("Error"), QObject::tr("Failed to update record."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::warning(nullptr, QObject::tr("Error"), QObject::tr("Record not found."), QMessageBox::Cancel);
    }
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
