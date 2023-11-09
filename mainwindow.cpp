#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQuery>
#include <QPainter>
#include <QPrinter>
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->bouton_menu->setStyleSheet();
    ui->groupBox->show();
    ui->ajout_entreprise->hide();
    ui->modifier_entreprise->hide();
ui->table_entreprise->setModel(e.afficher());
connect(ui->mod_id, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_mid_currentIndexChanged);
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

    ui->l_id->setStyleSheet(css);
    ui->l_nom->setStyleSheet(css);
    //ui->modifier->setStyleSheet(cssbtn);
    ui->l_etate->setStyleSheet(css);
    ui->l_email->setStyleSheet(css);
    ui->l_specialite->setStyleSheet(css);
    ui->l_adresse->setStyleSheet(css);
    ui->l_reception->setStyleSheet(css);
    ui->l_chercher->setStyleSheet(css);
    ui->chercher->setStyleSheet(cssbtn);
     ui->stat->setStyleSheet(cssbtn);
    ui->ajouter->setStyleSheet(cssbtn);
    ui->supprimer->setStyleSheet(cssbtn);
    ui->modifier_btn->setStyleSheet(cssbtn);
    ui->supprimer_2->setStyleSheet(css);
    ui->modi->setStyleSheet(cssbtn);
    ui->trier->setStyleSheet(cssbtn);
    ui->mod_enregistrer->setStyleSheet(cssbtn);
    ui->exportPDFBtn->setStyleSheet(cssbtn);
    ui->mod_annuler->setStyleSheet(cssbtn);
    ui->mod_id->setStyleSheet(css);
    ui->mod_nom->setStyleSheet(css);
    ui->mod_email->setStyleSheet(css);
    ui->mod_specialite->setStyleSheet(css);
    ui->mod_adresse->setStyleSheet(css);
    ui->mod_reception->setStyleSheet(css);
    ui->mod_etat->setStyleSheet(css);
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



            //ui->supprimer_2->setPlaceholderText("Entrez l'id de l'entreprise à supprimer ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_id->setPlaceholderText("Entrez l'id de l'entreprise ");
            ui->l_email->setPlaceholderText("Entrez l'e nom de'Email de l'entreprise ");
           // ui->L_specialite->setPlaceholderText("Entrez la specialité de l'entreprise ");
           // ui->l_reception->setPlaceholderText("Entrez la reception de la demande ");
            ui->l_nom->setPlaceholderText("Entrez le nom de l'entreprise ");
            ui->l_adresse->setPlaceholderText("Entrez l'e nom'adresse de l'entreprise ");
            //ui->l_etat->setPlaceholderText("Entrez l'etat de l'entreprise ");
            ui->mod_nom->setPlaceholderText("entrez le nouveau nom");
            ui->mod_adresse->setPlaceholderText("entrez la nouvelle adresse");
            ui->mod_email->setPlaceholderText("entrez le nouveau email");




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

        // Créer l'objet Entreprise avec les valeurs saisies
        Entreprise e(id, nom, email, specialite, adresse, reception_de_la_demande, etat);

        // Effectuer l'ajout de l'entreprise
        bool test = e.ajouter();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout avec succès.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            ui->table_entreprise->setModel(e.afficher());
            ui->l_id->clear();
            ui->l_nom->clear();
            ui->l_email->clear();
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

void MainWindow::on_chercher_clicked()
{
    QString idPrefix = ui->l_chercher->text();

       QSqlQueryModel* model = new QSqlQueryModel();
       model->setQuery(QString("SELECT id, nom, specialite, etat FROM entreprise WHERE id LIKE '%1%'").arg(idPrefix));
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialité"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

       // Afficher les résultats dans le QTableView
       ui->table_entreprise->setModel(model);
       ui->table_entreprise->resizeColumnsToContents();
}

void MainWindow::on_refresh_clicked()
{
    ui->table_entreprise->setModel(e.afficher());
     ui-> l_chercher->clear();
}

void MainWindow::on_modifier_btn_clicked()
{
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
    query.prepare("SELECT nom, email, specialite,adresse, reception_de_la_demande, etat FROM Entreprise WHERE id = :id");
    query.bindValue(":id", selectedId);

    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        QString email = query.value(1).toString();
        QString specialite = query.value(2).toString();
        QString adresse = query.value(3).toString();
        QString reception = query.value(4).toString();
        QString etat = query.value(5).toString();


        // Update the UI elements with the retrieved data
        ui->mod_nom->setText(nom);
        ui->mod_email->setText(email);
 ui->mod_adresse->setText(adresse);
        int index = ui->mod_specialite->findText(specialite);
        if (index != -1) {
            ui->mod_specialite->setCurrentIndex(index);
        }
         int index2 = ui->mod_etat->findText(etat);
        if (index2 != -1) {
            ui->mod_etat->setCurrentIndex(index2);
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
    QString reception_de_la_demande = ui->mod_reception->currentText();
    QString etat = ui->mod_etat->currentText();

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

    // Créer l'objet Entreprise avec les valeurs saisies
    Entreprise e(id, nom, email, specialite, adresse, reception_de_la_demande, etat);

    // Effectuer l'ajout de l'entreprise
    bool test = e.modifier();
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

/*void MainWindow::afficherStatistiques()
{
    Entreprise entreprise;
    QString statistiques = entreprise.obtenirStatistiques();

    if (!statistiques.isEmpty()) {
        QMessageBox::information(this, "Statistiques", statistiques);
    }
}
void MainWindow::on_pushButton_2_clicked()
{

}*/

void MainWindow::on_stat_clicked()
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
    s1 = countEtat("Non  accreditee");

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
