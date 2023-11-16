#include "entreprise.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QHeaderView>
#include<QTabWidget>
#include<QTableView>
#include <QMessageBox>
 #include <QtSql>
#include <QtCharts>
Entreprise::Entreprise()
{
    id=0;
    nom="";
    email="";
    specialite="";
    adresse="";
    reception_de_la_demande="";
    etat="";

}
Entreprise::Entreprise(int id,QString nom,QString email,QString specialite,QString adresse,QString reception_de_la_demande,QString etat)
{
    this->id=id;
    this->nom=nom;
    this->email=email;
    this->specialite=specialite;
    this->adresse=adresse;
    this->reception_de_la_demande=reception_de_la_demande;
    this->etat=etat;
}
int Entreprise::getid()
{
    return id;
}
QString Entreprise::getnom()
{
    return nom;
}
QString Entreprise::getemail()
{
    return email;
}
QString Entreprise::getspecialite()
{
    return specialite;
}
QString Entreprise::getadresse()
{
    return adresse;
}
QString Entreprise::getreception_de_la_demande()
{
    return reception_de_la_demande;
}
QString Entreprise::getetat()
{
    return etat;
}
void Entreprise::setid(int id)
{
    this->id=id;
}
void Entreprise::setnom(QString nom)
{
    this->nom=nom;
}
void Entreprise::setemail(QString email)
{
    this->email=email;
}
void Entreprise::setspecialite(QString specialite)
{
    this->specialite=specialite;
}
void Entreprise::setadresse(QString adresse)
{
    this->adresse=adresse;
}
void Entreprise::setreception_de_la_demande(QString reception_de_la_demande)
{
    this->reception_de_la_demande=reception_de_la_demande;
}
void Entreprise::setetat(QString etat)
{
    this->etat=etat;
}
/*void Entreprise::setetat(const QString& etat)
{
    this->etat = etat;
}*/
bool Entreprise::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("INSERT INTO ENTREPRISE (id, nom, email, specialite, adresse, reception_de_la_demande, etat) "
                  "VALUES (:id, :forename, :mail, :speciality, :adress, :recep, :etati)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", nom);
    query.bindValue(":mail", email);
    query.bindValue(":speciality", specialite);
    query.bindValue(":adress", adresse);
    query.bindValue(":recep", reception_de_la_demande);
    query.bindValue(":etati", etat);
    /*ui->l_etate->addItem("Accréditée");
    ui->l_etate->addItem("Non accréditée ");*/
    return query.exec();
}
bool Entreprise::supprimer(int id)
{
            QSqlQuery query;
          query.prepare("delete from entreprise where id=:id");
          query.bindValue(0,id);
          return query.exec();
}
QSqlQueryModel *Entreprise::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT id , nom , specialite , etat FROM entreprise");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    return model;
}
bool Entreprise::modi(int nid)
{
    QSqlQuery query;
    query.prepare("UPDATE Entreprise SET nom=:nom, email=:email, specialite=:specialite,  adresse=:adresse, reception_de_la_demande=:reception, etat=:etat WHERE id=:id");
            query.bindValue(":id",nid);
            query.bindValue(":nom",nom);
            query.bindValue(":email",email);
            query.bindValue(":specialite",specialite);
            query.bindValue(":adresse",adresse);
            query.bindValue(":reception",reception_de_la_demande);
            query.bindValue(":etat",etat);
            return query.exec();

}
bool Entreprise::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE Entreprise SET nom=:nom, email=:email, specialite=:specialite,  adresse=:adresse, reception_de_la_demande=:reception, etat=:etat WHERE id=:id");
            query.bindValue(":id",id);
            query.bindValue(":nom",nom);
            query.bindValue(":email",email);
            query.bindValue(":specialite",specialite);
            query.bindValue(":adresse",adresse);
            query.bindValue(":reception",reception_de_la_demande);
            query.bindValue(":etat",etat);
            return query.exec();

}
QSqlQueryModel* Entreprise::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id ,nom,specialite,etat  FROM Entreprise order BY specialite ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("specialité"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    return model;
}
Entreprise Entreprise::chercherParId(int id)
{
    Entreprise entreprise;

    QSqlQuery query;
    query.prepare("SELECT id, nom, specialite, etat FROM entreprise WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        entreprise.setid(query.value(0).toInt());
        entreprise.setnom(query.value(1).toString());
        entreprise.setspecialite(query.value(2).toString());
        entreprise.setetat(query.value(3).toString());
    }

    return entreprise;
}
/*QString Entreprise::obtenirStatistiques()
{
    QString statistiques;

    // Effectuer la requête SQL pour obtenir les statistiques
    QString queryStr = "SELECT etat, COUNT(*) FROM Entreprise GROUP BY etat";
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        statistiques = "Erreur lors de l'exécution de la requête : " + query.lastError().text();
    } else {
        QPieSeries *series = new QPieSeries();

        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(etat, count);
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des entreprises par état");

        // Créer le widget de diagramme circulaire et l'afficher
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        chartView->resize(400, 300); // Définir la taille du widget de diagramme circulaire
        chartView->show();
    }

    return statistiques;
}*/
