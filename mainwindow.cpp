#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"
#include<QSqlQuery>
#include <QPainter>
#include <QPrinter>
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QSqlError>
#include "email.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets/QLineEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include"twiliomanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->bouton_menu->setStyleSheet();
     on_stat();
    ui->groupBox->show();
    ui->ajout_entreprise->hide();
     ui->group_email->hide();
    ui->modifier_entreprise->hide();
    ui->localisation->hide();
    ui->sms->hide();

ui->table_entreprise->setModel(e.afficher());
connect(ui->mod_id, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_mid_currentIndexChanged);
connect(ui->l_chercher, &QLineEdit::textChanged, this, &MainWindow::on_texte_recherche_textChanged);
QSqlQuery query;
            query.exec("SELECT id FROM Entreprise");

            // Populate the combobox with data from the database
            while (query.next()) {
                int id = query.value(0).toInt();
                ui->supprimer_2->addItem(QString::number(id));
            }
QString css="color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
            "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
            "display: flex;"
            "width: 484px;"
            "height: 60px;"
            "padding: 20px 16px;"
            "align-items: center;"
            "spacing: 24px;"
            "flex: 0;" ;
QString cssbtn="QPushButton"
    "{background:none;"
    "text-align: center;"
    "padding-left:10px;"
    "border-radius: 10px;"

    "background-color :  rgba(189, 76, 224, 1);"
"color:#fff;"
    "font-family: Arial, sans-serif; "
    "font-size: 20px;"
    "font-weight: bold; } "

"QPushButton:hover"
"{"
    "border : 2px solid  rgba(189, 76, 224, 1);	"
    "background-color: rgba(84, 16, 149, 1);"

"}";
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

    ui->l_id->setStyleSheet(css);
    ui->l_nom->setStyleSheet(css);
     ui->l_numero->setStyleSheet(css);
    //ui->modifier->setStyleSheet(cssbtn);
    ui->l_etate->setStyleSheet(css);
     ui->email_id->setStyleSheet(css);
    ui->l_email->setStyleSheet(css);
    ui->l_specialite->setStyleSheet(css);
    ui->l_adresse->setStyleSheet(css);
    ui->l_reception->setStyleSheet(css);
    ui->l_chercher->setStyleSheet(css);
    ui->sms_body->setStyleSheet(css);
    ui->sms_nom->setStyleSheet(css);
    ui->sms_numero->setStyleSheet(css);
    ui->localisation_nom->setStyleSheet(css);
    ui->chercher->setStyleSheet(cssbtn);
ui->sms_annuler->setStyleSheet(cssbtn);
ui->sms_envoyer->setStyleSheet(cssbtn);
   // ui->ajouter->setStyleSheet(cssbtn);
    ui->supprimer->setStyleSheet(cssbtn);
    ui->modifier_btn->setStyleSheet(cssbtn);
    ui->supprimer_2->setStyleSheet(css);
    ui->destinataireEmail->setStyleSheet(css);
    ui->bodyEmail->setStyleSheet(css);
    ui->objetEmail->setStyleSheet(css);
   // ui->trier->setStyleSheet(cssbtn);
    ui->mod_enregistrer->setStyleSheet(cssbtn);
     ui->annuler_email->setStyleSheet(cssbtn);
      ui->envoyer->setStyleSheet(cssbtn);
    ui->mod_annuler->setStyleSheet(cssbtn);
   ui->mod_id->setStyleSheet(css);
    ui->mod_nom->setStyleSheet(css);
    ui->mod_email->setStyleSheet(css);
    ui->mod_numero->setStyleSheet(css);
    ui->mod_specialite->setStyleSheet(css);
    ui->mod_adresse->setStyleSheet(css);
    ui->mod_reception->setStyleSheet(css);
    ui->mod_etat->setStyleSheet(css);
   /* ui->table_entreprise->setStyleSheet("QTableView{color: #DCBFFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                               "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                               "display: flex;"
                                               "width: 484px;"
                                               "height: 60px;"
                                               "padding: 20px 16px;"
                                               "align-items: center;"
                                               "spacing: 24px;"
                                               "flex: 0;}"
                                                " color: black; background-color: rgba(0, 0, 0, 0.5); ");*/

    ui->table_entreprise->setStyleSheet("QTableView {"
                                        "color: #DCBFFF;"
                                        "border-radius: 20px;"
                                        "border: 1px solid rgba(51, 66, 255, 0.0);"
                                        "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.0), stop: 0.5 rgba(17, 16, 24, 0.51));"
                                        "display: flex;"
                                        "width: 484px;"
                                        "height: 60px;"
                                        "padding: 20px 16px;"
                                        "align-items: center;"
                                        "spacing: 24px;"
                                        "flex: 0;"
                                    "}"
                                    "QHeaderView::section {"
                                        "background-color: #363062;"
                                        "color: white;"
                                    "}");

            //ui->supprimer_2->setPlaceholderText("Entrez l'id de l'entreprise à supprimer ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_id->setPlaceholderText("Entrez l'id de l'entreprise ");
            ui->l_email->setPlaceholderText("Entrez l'Email de l'entreprise ");
           // ui->L_specialite->setPlaceholderText("Entrez la specialité de l'entreprise ");
           // ui->l_reception->setPlaceholderText("Entrez la reception de la demande ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_adresse->setPlaceholderText("Entrez l'e nom'adresse de l'entreprise ");
            //ui->l_etat->setPlaceholderText("Entrez l'etat de l'entreprise ");
            ui->mod_nom->setPlaceholderText("entrez le nouveau nom");
            ui->mod_adresse->setPlaceholderText("entrez la nouvelle adresse");
            ui->mod_email->setPlaceholderText("entrez le nouveau email");
            ui->l_chercher->setPlaceholderText("entrez un id à rechercher");





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

    QString idString = ui->l_id->text();
        QString nom = ui->l_nom->text();
        QString email = ui->l_email->text();
        QString specialite = ui->l_specialite->currentText();
        QString adresse = ui->l_adresse->text();
        QString reception_de_la_demande = ui->l_reception->currentText();
        QString etat = ui->l_etate->currentText();
        QString numero = ui->l_numero->text();

        // Vérifier si tous les champs sont remplis
        if (idString.isEmpty() || nom.isEmpty() || email.isEmpty() || adresse.isEmpty())
        {
            QMessageBox::critical(nullptr, QObject::tr("Champs manquants"), QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
            return;
        }

        // Vérifier si l'ID est valide
        bool isIdValid = false;
        int id = idString.toInt(&isIdValid);
        if (!isIdValid || QString::number(id).length() > 7)
        {
            QMessageBox::critical(nullptr, QObject::tr("ID invalide"), QObject::tr("ID invalide. Veuillez entrer un ID valide (jusqu'à 7 chiffres)."), QMessageBox::Cancel);
            return;
        }

        // Vérifier si l'e-mail est valide
        QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
        QRegularExpressionMatch match = emailRegex.match(email);
        if (!match.hasMatch())
        {
            QMessageBox::critical(nullptr, QObject::tr("Email invalide"), QObject::tr("Le format de l'e-mail est invalide. Veuillez entrer un e-mail valide."), QMessageBox::Cancel);
            return;
        }
        // Vérifier si le numéro correspond au format requis
        QRegularExpression regex("^[2|5|7|9]\\d{7}$"); // Expression régulière : commence par 2, 5, 7 ou 9, suivi de 7 chiffres

        if (!regex.match(numero).hasMatch())
        {
            QMessageBox::critical(nullptr, QObject::tr("Numéro invalide"), QObject::tr("Le numéro doit contenir 8 chiffres et commencer par 2, 5, 7 ou 9."), QMessageBox::Cancel);
            return;
        }
        // Créer l'objet Entreprise avec les valeurs saisies
        Entreprise e(id, nom, email, specialite, adresse, reception_de_la_demande, etat, numero);

        // Effectuer l'ajout de l'entreprise
        bool test = e.ajouter();
        if (test)
        {
            on_stat();
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout avec succès.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            ui->table_entreprise->setModel(e.afficher());
            ui->l_id->clear();
            ui->l_nom->clear();
            ui->l_email->clear();
            ui->l_numero->clear();
            ui->l_specialite->setCurrentIndex(0);
            ui->l_adresse->clear();
            ui->l_reception->setCurrentIndex(0);
            ui->l_etate->setCurrentIndex(0);
            ui->ajout_entreprise->hide();
            ui->groupBox->show();
            ui->supprimer_2->clear();
            QSqlQuery query;
                        query.exec("SELECT id FROM Entreprise");

                        // Populate the combobox with data from the database
                        while (query.next()) {
                            int id = query.value(0).toInt();
                            ui->supprimer_2->addItem(QString::number(id));
                        }
            }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Échec de l'ajout.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
  }
void MainWindow::on_supprimer_clicked()
{

    QString idString = ui->supprimer_2->currentText();
        if (idString.isEmpty()) {
            QMessageBox::warning(nullptr, QObject::tr("Invalid Input"), QObject::tr("entrez un id pour la suppression."), QMessageBox::Ok);
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
            QMessageBox::warning(nullptr, QObject::tr("ID Not Found"), QObject::tr("id introuvable!."), QMessageBox::Ok);
            return;
        }

        bool test = e1.supprimer(e1.getid());

        if (test)
        {
             on_stat();
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression avec succès.\n""Click cancel to exit."), QMessageBox::Cancel);
            ui->table_entreprise->setModel(e.afficher());
            ui->supprimer_2->clear();
            QSqlQuery query;
                        query.exec("SELECT id FROM Entreprise");

                        // Populate the combobox with data from the database
                        while (query.next()) {
                            int id = query.value(0).toInt();
                            ui->supprimer_2->addItem(QString::number(id));
                        }

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
     ui->l_numero->clear();
    ui->l_specialite->setCurrentIndex(0);
    ui->l_adresse->clear();
    ui->l_reception->setCurrentIndex(0);
    ui->l_etate->setCurrentIndex(0);
}
void MainWindow::on_modi_clicked()
{
    Entreprise e;
    e.setid(ui->l_id->text().toInt());
    e.setnom(ui->l_nom->text());
    e.setemail(ui->l_email->text());
    e.setspecialite(ui->l_specialite->currentText());
    e.setadresse(ui->l_adresse->text());
    e.setreception_de_la_demande(ui->l_reception->currentText());
    bool test=e.modi(e.getid());

    if(test)
    {
        on_stat();
        QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("modification effectuée\nClick Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("modification non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
     ui->table_entreprise->setModel(e.afficher());
}


void MainWindow::on_trier_clicked()
{
    ui->table_entreprise->setModel(e.tri());
}
void MainWindow::on_refresh_clicked()
{
    ui->table_entreprise->setModel(e.afficher());
     ui-> l_chercher->clear();
}

void MainWindow::on_modifier_btn_clicked()
{
    ui->mod_id->clear();
    QSqlQuery query;
    query.exec("SELECT id FROM Entreprise");

    // Populate the combobox with data from the database
    while (query.next()) {
        int id = query.value(0).toInt();
        ui->mod_id->addItem(QString::number(id));
    }
    int selectedid=ui->mod_id->currentText().toInt();
    updateUI(selectedid);
    ui->modifier_entreprise->show();
    ui->groupBox->hide();
}
void MainWindow::on_retour_clicked()
{
    ui->modifier_entreprise->hide();
    ui->groupBox->show();
}
void MainWindow::on_mid_currentIndexChanged(int index)
{
    // Get the selected ID from the combo box
    int selectedId = ui->mod_id->itemText(index).toInt();

    // Call the function to update the UI with the selected ID's data
    updateUI(selectedId);

    // Show the appropriate UI elements
    ui->groupBox->hide();
    ui->ajout_entreprise->hide();
    ui->modifier_entreprise->show();
}

void MainWindow::updateUI(int selectedId)
{
    QSqlQuery query;

    // Retrieve and set values for other UI elements based on the selected ID
    query.prepare("SELECT * FROM Entreprise WHERE id = :id");
    query.bindValue(":id", selectedId);

    if (query.exec() && query.next()) {

        QString nom = query.value(1).toString();
        QString email = query.value(2).toString();
        QString specialite = query.value(3).toString();
        QString adresse = query.value(4).toString();
        QString reception = query.value(5).toString();
        QString etat = query.value(6).toString();
        QString numero = query.value(7).toString();


        // Update the UI elements with the retrieved data
        ui->mod_nom->setText(nom);
         ui->mod_numero->setText(numero);
        ui->mod_email->setText(email);
        qDebug()<<"Etat: "<<etat;

        ui->mod_adresse->setText(adresse);
        int index = ui->mod_etat->findText(etat);
        qDebug()<<"index etat: "<<index;
        if (index != -1) {
            ui->mod_etat->setCurrentIndex(index);
        }
         qDebug() << index <<endl;
         int index2 = ui->mod_specialite->findText(specialite);

        if (index2 != -1) {
            ui->mod_specialite->setCurrentIndex(index2);
        }
        int index3 = ui->mod_reception->findText(reception);
        if (index3 != -1) {
            ui->mod_reception->setCurrentIndex(index3);
        }

    }
}
void MainWindow::on_mod_enregistrer_clicked()
{
    QString idString = ui->mod_id->currentText();
    QString nom = ui->mod_nom->text();
    QString email = ui->mod_email->text();
    QString specialite = ui->mod_specialite->currentText();
    QString adresse = ui->mod_adresse->text();
    QString numero = ui->mod_numero->text();
    QString reception_de_la_demande = ui->mod_reception->currentText();
    QString etat = ui->mod_etat->currentText();

    // Vérifier si tous les champs sont remplis
    if (idString.isEmpty() || nom.isEmpty() || email.isEmpty() || adresse.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Champs manquants"), QObject::tr("Veuillez remplir tous les champs."), QMessageBox::Cancel);
        return;
    }
    // Vérifier si le numéro correspond au format requis
    QRegularExpression regex("^[2|5|7|9]\\d{7}$"); // Expression régulière : commence par 2, 5, 7 ou 9, suivi de 7 chiffres

    if (!regex.match(numero).hasMatch())
    {
        QMessageBox::critical(nullptr, QObject::tr("Numéro invalide"), QObject::tr("Le numéro doit contenir 8 chiffres et commencer par 2, 5, 7 ou 9."), QMessageBox::Cancel);
        return;
    }
    // Vérifier si l'ID est valide
    bool isIdValid = false;
    int id = idString.toInt(&isIdValid);
    if (!isIdValid || QString::number(id).length() > 7)
    {
        QMessageBox::critical(nullptr, QObject::tr("ID invalide"), QObject::tr("ID invalide. Veuillez entrer un ID valide (jusqu'à 7 chiffres)."), QMessageBox::Cancel);
        return;
    }

    // Vérifier si l'e-mail est valide
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    QRegularExpressionMatch match = emailRegex.match(email);
    if (!match.hasMatch())
    {
        QMessageBox::critical(nullptr, QObject::tr("Email invalide"), QObject::tr("Le format de l'e-mail est invalide. Veuillez entrer un e-mail valide."), QMessageBox::Cancel);
        return;
    }

    // Créer l'objet Entreprise avec les valeurs saisies
    Entreprise e(id, nom, email, specialite, adresse, reception_de_la_demande, etat, numero);

    // Effectuer l'ajout de l'entreprise
       ui->supprimer_2->clear();
    QSqlQuery query;
                query.exec("SELECT id FROM Entreprise");

                // Populate the combobox with data from the database
                while (query.next()) {
                    int id = query.value(0).toInt();
                    ui->supprimer_2->addItem(QString::number(id));
                }
    //bool test = e.modifier();
    ui->table_entreprise->setModel(e.afficher());
    ui->modifier_entreprise->hide();
    ui->groupBox->show();
}
void MainWindow::on_exportPDFBtn_clicked()
{
    QPixmap pix(ui->table_entreprise->size());
    QPainter painter(&pix);
    ui->table_entreprise->render(&painter);
    painter.end();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);
    QString outputPath = "C:/Users/noura/OneDrive/Bureau/projetui/LocalData/test.pdf";

    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(outputPath);

    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(pix.width());
    double yscale = printer.pageRect().height() / double(pix.height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                      printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
    painter.translate(-ui->table_entreprise->width() / 2, -ui->table_entreprise->height() / 2);
    painter.drawPixmap(0, 0, pix);

    //QTextDocument doc;
    //doc.setHtml("htmlcontent");
    //doc.drawContents(&painter);
    painter.end();
    QMessageBox::information(this,"Done","PDF is saved successfully");

    // Open the generated PDF
    QDesktopServices::openUrl(QUrl::fromLocalFile(outputPath));
}


int MainWindow::countEtat(const QString& etat)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(etat) FROM Entreprise WHERE etat = :etat");
    query.bindValue(":etat", etat);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}
void MainWindow::on_stat()
{
    QList<QWidget*> childWidgets = ui->lab_stat->findChildren<QWidget*>();
    for (QWidget* childWidget : childWidgets) {
        childWidget->deleteLater();

    }
    //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
    ui->lab_stat->clear();
    ui->lab_stat->hide();

    float s0, s1;
    s0 = countEtat("Accreditee");
    s1 = countEtat("Non accreditee");

    float stat = s0 + s1;
    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

    QString ch1 = QString("Accreditee: %1%").arg(x);
    QString ch2 = QString("Non  accreditee: %1%").arg(y);

    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.39);
    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();

    slice->setLabelColor(QColor("#FFFFFF"));
    slice->setBrush(QColor(189, 76, 224, 1));

    QPieSlice *slice1 = series->append(ch2, y);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor("#FFFFFF"));
    slice1->setBrush(QColor(84, 16, 149, 1));

    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //chart->setTitle("Statistique entre l homme et la femme");
    //chart->setTheme(QChart::ChartThemeBlueIcy);
    QBrush backgroundBrush(QColor(187,93,87,0));
    chart->setBackgroundBrush(backgroundBrush);
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->lab_stat->size());
    chartview->setParent(ui->lab_stat);
    ui->lab_stat->setStyleSheet("background:transparent; color:white; ");
    ui->lab_stat->show();
}
void MainWindow::on_mod_annuler_clicked()
{
    ui->modifier_entreprise->hide();
    ui->groupBox->show();
}
void MainWindow::on_texte_recherche_textChanged(const QString &text)
{
    QSqlQueryModel* searchModel = new QSqlQueryModel();
    searchModel->setQuery(QString("SELECT id, nom, specialite, etat FROM entreprise WHERE id LIKE '%1%'").arg(text));

    if (searchModel->rowCount() > 0) {
        // If the search result is not empty
        ui->table_entreprise->setModel(searchModel);
}
        if (searchModel->rowCount() == 0) {
            // If the search result is not empty
            ui->table_entreprise->setModel(searchModel);
}
        // Adjust the header view as needed
        QHeaderView* headerView = ui->table_entreprise->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);
}





void MainWindow::on_retour_local_clicked()
{
    ui->localisation->hide();
    ui->groupBox->show();
}


void MainWindow::on_email_clicked()
{
    ui->group_email->show();
    ui->groupBox->hide();
    ui->email_id->clear();

    QSqlQuery query;
    query.exec("SELECT id, nom, email FROM Entreprise");

    // Clear the combobox before populating it with data
    ui->email_id->clear();

    // Add an empty item to the combobox as the first option
    ui->email_id->addItem("");

    // Populate the combobox with data from the database
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString email = query.value(2).toString();

        ui->email_id->addItem(QString::number(id));
    }

    // Connect the currentIndexChanged signal of the combobox to a slot
    connect(ui->email_id, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (index > 0) { // Check if an item other than the empty item is selected
            // Fetch the selected ID from the combobox
            int selectedId = ui->email_id->itemText(index).toInt();

            // Fetch the associated attributes from the database based on the selected ID
            QSqlQuery selectedQuery;
            selectedQuery.prepare("SELECT nom, email FROM Entreprise WHERE id = ?");
            selectedQuery.addBindValue(selectedId);
            if (selectedQuery.exec() && selectedQuery.next()) {
                // Update the line edits with the fetched attribute values
                ui->email_nom->setText(selectedQuery.value(0).toString());
                ui->destinataireEmail->setText(selectedQuery.value(1).toString());
            }
        } else {
            // If the empty item is selected, clear the line edits
            ui->email_nom->clear();
            ui->destinataireEmail->clear();
        }
    });
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->group_email->hide();
    ui->groupBox->show();
}
void MainWindow::on_envoyer_clicked()
{
    mailer::sendEmail(ui->destinataireEmail->text(), ui->objetEmail->text(), ui->bodyEmail->text());
    ui->group_email->hide();
    ui->groupBox->show();
}
void MainWindow::on_annuler_email_clicked()
{
    ui->destinataireEmail->clear();
    ui->objetEmail->clear();
    ui->bodyEmail->clear();
    /*ui->group_email->hide();
    ui->groupBox->show();*/
}
void MainWindow::on_sms_annuler_clicked()
{
    ui->sms->hide();
    ui->groupBox->show();
}

/*void MainWindow::on_sms_btn_clicked()
{
    ui->sms->show();
    ui->groupBox->hide();
    ui->email_nom->clear();
    QSqlQuery query;
    query.exec("SELECT nom, numero FROM Entreprise");

    // Clear the combobox before populating it with data
    ui->sms_nom->clear();

    // Add an empty item to the combobox as the first option
    ui->sms_nom->addItem("");

    // Populate the combobox with data from the database
    while (query.next()) {
        QString nom = query.value(0).toString();
        QString numero = query.value(1).toString();

        ui->sms_nom->addItem(nom);
    }

    // Connect the currentIndexChanged signal of the combobox to a slot
    connect(ui->sms_nom, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (index > 0) { // Check if an item other than the empty item is selected
            // Fetch the selected name from the combobox
            QString selectedName = ui->sms_nom->currentText();

            // Fetch the associated attributes from the database based on the selected name
            QSqlQuery selectedQuery;
            selectedQuery.prepare("SELECT numero FROM Entreprise WHERE nom = ?");
            selectedQuery.addBindValue(selectedName);
            if (selectedQuery.exec() && selectedQuery.next()) {
                // Update the line edit with the fetched attribute value
                ui->sms_numero->setText(selectedQuery.value(0).toString());
            }
        } else {
            // If the empty item is selected, clear the line edit
            ui->sms_numero->clear();
        }
    });
}*/


void MainWindow::on_sms_btn_clicked()
{
    ui->sms->show();
    ui->groupBox->hide();
    ui->sms_nom->clear();

    QSqlQuery query;
    query.exec("SELECT nom, numero FROM Entreprise");

    // Clear the combobox before populating it with data
    ui->sms_nom->clear();

    // Add an empty item to the combobox as the first option
    ui->sms_nom->addItem("");

    // Populate the combobox with data from the database
    while (query.next()) {
        QString nom = query.value(0).toString();
        QString numero = query.value(1).toString();

        ui->sms_nom->addItem(nom);
    }

    // Connect the currentIndexChanged signal of the combobox to a slot
    connect(ui->sms_nom, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (index > 0) { // Check if an item other than the empty item is selected
            // Fetch the selected name from the combobox
            QString selectedName = ui->sms_nom->currentText();

            // Fetch the associated attributes from the database based on the selected name
            QSqlQuery selectedQuery;
            selectedQuery.prepare("SELECT numero FROM Entreprise WHERE nom = ?");
            selectedQuery.addBindValue(selectedName);
            if (selectedQuery.exec() && selectedQuery.next()) {
                // Update the line edit with the fetched attribute value
                ui->sms_numero->setText(selectedQuery.value(0).toString());
            }
        } else {
            // If the empty item is selected, clear the line edit
            ui->sms_numero->clear();
        }
    });

}

void MainWindow::on_sms_envoyer_clicked()
{
    qDebug()<<"sms 1";
    TwilioManager sms;
    sms.sendSMS(ui->sms_body->text());
     qDebug()<<"sms 2";
}

/*void MainWindow::on_sms_envoyer_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkRequest request(QUrl("https://api.twilio.com/2010-04-01/Accounts/AC2a40f57200807ece9911a66498d233e1/Messages.json"));

        // Set up headers and authentication
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QString credentials = "AC2a40f57200807ece9911a66498d233e1:e81bbb24ed9b4c8aed97d2f3a0550406";
        QString base64Credentials = QString(credentials.toUtf8().toBase64());
        request.setRawHeader("Authorization", "Basic " + base64Credentials.toUtf8());

        // Prepare POST data
        QUrlQuery params;
        params.addQueryItem("To", "+21655475804");
        params.addQueryItem("From", "+12672974846");
        params.addQueryItem("Body", "Hello from Qt!");
        QByteArray postData = params.query().toUtf8();
        // Before sending the request
        qDebug() << "Request URL:" << request.url().toString();
        qDebug() << "Request Headers:" << request.rawHeaderList();
        qDebug() << "Request Body:" << postData;


        // Send the request
        QNetworkReply *reply = manager->post(request, postData);

        // Connect to the finished signal
        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QString response = QString::fromUtf8(reply->readAll());
                // Log the full response
                           qDebug() << "Response Headers:" << reply->rawHeaderList();
                           qDebug() << "Response Body:" << reply->readAll();

                           qDebug() << "Success!";
            } else {
                qDebug() << "Error:" << reply->errorString();

                           // Log the full error response
                           qDebug() << "Response Headers:" << reply->rawHeaderList();
                           qDebug() << "Response Body:" << reply->readAll();
            }
            reply->deleteLater();
        });

    }*/


