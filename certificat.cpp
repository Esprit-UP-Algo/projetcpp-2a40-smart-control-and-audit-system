 #include "certificat.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QDate>
#include <QObject>




Certificat::Certificat()
{
id=0; date=QDate::currentDate() ; type="" ; duree="";
}
Certificat::Certificat(int id ,QString type,QDate date,QString duree)
{

    this->id=id ;
    this->type=type ;
    this->date=date;
     this->duree=duree;
}

int Certificat::getid() {return id;}
QString Certificat:: gettype(){return type;}
QDate Certificat:: getdate(){return date;}
void Certificat::setid(int id){this->id=id;};
void Certificat::settype(QString type){this->type=type;}
void Certificat::setdate(QDate date){this->date=date;}
void Certificat::setduree(QString duree){this->duree=duree;}
QString Certificat::getduree(){return duree;}

bool Certificat::ajouter()
{


  QSqlQuery query;

  query.prepare("INSERT INTO GESTION_CERTIFICAT (id, datev, type,duree) VALUES(:id, :date, :type,:duree)");

       query.bindValue(":id", id);
       query.bindValue(":date", date);
       query.bindValue(":type", type);
       query.bindValue(":duree", duree);


  return  query.exec();

}
bool Certificat::supprimer(int id)
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString date_String=date.toString("dd-MM-yyyy");

    query.prepare("Delete from GESTION_CERTIFICAT where id=:id ");
         query.bindValue(0, id);
         query.bindValue(1, date);
         query.bindValue(2, type);
         query.bindValue(3, duree);

    return  query.exec();




}
QSqlQueryModel* Certificat::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT id,type,datev,duree FROM GESTION_CERTIFICAT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("type"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("datev"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("duree"));

    return model;
}

bool Certificat::modifier(int nid,QDate date,QString type,QString duree)
{

    QSqlQuery query;

    query.prepare("UPDATE GESTION_CERTIFICAT SET DATEV=:date , TYPE=:type , duree=:duree where id=:nid ");
         query.bindValue(":nid", nid);
         query.bindValue(":date", date);
         query.bindValue(":type", type);
         query.bindValue(":duree", duree);

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


QSqlQueryModel*Certificat::afficher1()

{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id,type,datev,duree FROM GESTION_CERTIFICAT ORDER BY datev DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
    return model;
}


 Certificat Certificat::chercherParDate(const QDate &date)
  {
     Certificat Certificat;

     QSqlQuery query;
     query.prepare("SELECT * FROM GESTION_CERTIFICAT WHERE date = :datev");
     query.bindValue(":datev", date);

     if (query.exec() && query.next()) {

         Certificat.setid(query.value(0).toInt());
         Certificat.setdate(query.value(1).toDate());
         Certificat.settype(query.value(2).toString());
         Certificat.setduree(query.value(3).toString());
     }

     return Certificat;
 }
 bool Certificat::idExists(int id)
 {
     QSqlQuery query;
     query.prepare("SELECT COUNT(*) FROM GESTION_CERTIFICAT WHERE ID = :id");
     query.bindValue(":id", id);

     if (query.exec() && query.next()) {
         int count = query.value(0).toInt();
         return count > 0;
     }

     return false;
 }









