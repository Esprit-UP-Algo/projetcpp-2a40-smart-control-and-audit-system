#include "formation.h"
#include <QDate>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QHeaderView>
#include <QTableWidget>
formation::formation()
{
IDFOR=0;
TYPE_DE_FORMATION="";
DUREE_DE_LA_FORMATION="";
FORMATEUR="";
DATE_DE_DEBUT=QDate::currentDate();
DATE_DE_FIN=QDate::currentDate();
NB_PLACE=0;
}

formation::formation(int IDFOR ,QString TYPE_DE_FORMATION ,QString FORMATEUR ,QDate DATE_DE_DEBUT,QDate DATE_DE_FIN,QString DUREE_DE_LA_FORMATION,int NB_PLACE)
{

    this->IDFOR=IDFOR;
    this->TYPE_DE_FORMATION=TYPE_DE_FORMATION;
    this->DUREE_DE_LA_FORMATION=DUREE_DE_LA_FORMATION;
    this->FORMATEUR=FORMATEUR;
   this-> DATE_DE_DEBUT=DATE_DE_DEBUT;
    this->DATE_DE_FIN=DATE_DE_FIN;
   this-> NB_PLACE=NB_PLACE;

}
int formation:: getIDFOR(){return IDFOR;}
QString formation::getype(){return  TYPE_DE_FORMATION ;}
QString formation::getduree(){return DUREE_DE_LA_FORMATION ;}
QString formation::getformateur(){return   FORMATEUR;}
QDate formation::getdebut(){return  DATE_DE_DEBUT ;}
QDate formation::getfin(){return   DATE_DE_FIN;}
int formation::getnbplace(){return   NB_PLACE;}


void formation::setIDFOR(int IDFOR) {this->IDFOR=IDFOR;}
void formation::settype(QString   TYPE_DE_FORMATION){this-> TYPE_DE_FORMATION= TYPE_DE_FORMATION ;}
void formation::setduree(QString DUREE_DE_LA_FORMATION){this->DUREE_DE_LA_FORMATION=DUREE_DE_LA_FORMATION;}
void formation::setformateur(QString FORMATEUR){this->FORMATEUR=FORMATEUR;}
void formation::setdebut(QDate DATE_DE_DEBUT){this-> DATE_DE_DEBUT= DATE_DE_DEBUT;}
void formation::setfin(QDate DATE_DE_FIN){this-> DATE_DE_FIN=DATE_DE_FIN ;}
void formation::setnbplace(int NB_PLACE){this->NB_PLACE=NB_PLACE;}



    bool formation::ajouter()
    {
        QSqlQuery query;

        query.prepare("INSERT INTO formation (IDFOR,FORMATEUR,TYPE_DE_FORMATION,DATE_DE_DEBUT,DATE_DE_FIN,DUREE_DE_LA_FORMATION,NB_PLACE) "
                      "VALUES (:IDFOR, :FOR, :TYPE_DE_FORMATION, :DATE_DE_DEBUT, :DATE_DE_FIN, :DUREE_DE_LA_FORMATION, :NB_PLACE)");

        query.bindValue(":IDFOR", IDFOR);
        query.bindValue(":FOR", FORMATEUR);
        query.bindValue(":TYPE_DE_FORMATION", TYPE_DE_FORMATION);
        query.bindValue(":DATE_DE_DEBUT", DATE_DE_DEBUT);
        query.bindValue(":DATE_DE_FIN",DATE_DE_FIN);
        query.bindValue(":DUREE_DE_LA_FORMATION",DUREE_DE_LA_FORMATION);
        query.bindValue(":NB_PLACE", NB_PLACE);

        return query.exec();
    }


QSqlQueryModel* formation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM formation");
         model->setHeaderData(0, Qt::Horizontal,QObject:: tr("IDFOR"));
         model->setHeaderData(1, Qt::Horizontal,QObject:: tr("FORMATEUR"));
         model->setHeaderData(2, Qt::Horizontal,QObject:: tr("TYPE_DE_FORMATION"));
         model->setHeaderData(3, Qt::Horizontal,QObject:: tr("DATE_DE_DEBUT"));
         model->setHeaderData(4, Qt::Horizontal,QObject:: tr("DATE_DE_FIN"));
         model->setHeaderData(5, Qt::Horizontal,QObject:: tr("DUREE_DE_LA_FORMATION"));
         model->setHeaderData(6, Qt::Horizontal,QObject:: tr("NB_PLACE"));

         // Create a table view
            QTableView* tableView = new QTableView;
            tableView->setModel(model);

            // Get the header view
            QHeaderView* headerView = tableView->horizontalHeader();
            headerView->setSectionResizeMode(QHeaderView::Stretch); // Optional: Adjust the section resize mode
    return model;
}

bool formation::supprimer(int id)
{QSqlQuery query;
 query.prepare("Delete FROM formation where IDFOR=:id");
    query.bindValue(0,id);
 return query.exec();
}

bool formation::idExists(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM formation WHERE IDFOR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}
