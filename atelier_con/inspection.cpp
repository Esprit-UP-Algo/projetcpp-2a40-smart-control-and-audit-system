#include "inspection.h"
#include<QSqlQuery>
#include<QDebug>
#include <QObject>
Inspection::Inspection()
{
int id=0;
QString nom="";
QString prenom="";
}
Inspection :: Inspection(int id,QString nom,QString prenom)
{
    this->nom=nom;
    this->prenom=prenom;
    this->id=id;
}
int Inspection:: getid(){return id;}
QString Inspection::getnom(){return nom;}
QString Inspection::getprenom (){return prenom;}
void  Inspection::setid(int id){this->id=id;}
void Inspection::setnom(QString nom ){this->nom=nom;}
void Inspection::setprenom(QString prenom){this->prenom=prenom ;}
bool Inspection::ajouter ()
{
    bool test=false;
    QSqlQuery query;
    QString id_string=QString:: number (id);
          query.prepare("INSERT INTO inspection (id, nom, prenom) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", id_string );
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          return query.exec();
}

QSqlQueryModel * Inspection :: afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * INSPECTION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));

    return model;
}
bool Inspection::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString:: number (id);
          query.prepare(" Delete form INSPECTION where id =:id");
          query.bindValue(":id", id );
          return query.exec();
}
