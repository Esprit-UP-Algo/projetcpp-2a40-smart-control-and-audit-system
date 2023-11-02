#include "entreprise.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

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
    model->setQuery("SELECT * FROM entreprise");
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
