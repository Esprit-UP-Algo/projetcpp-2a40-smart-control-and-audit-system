#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Employe::Employe()
{
    id=0;
    nom="";
    prenom="";
    date_naissance=QDate::currentDate();
    poste="";sexe="";
    email="";
    date_embauche=QDate::currentDate();
    fin_contrat=QDate::currentDate();
    numero_telephone="";
}

Employe::Employe(int id, QString nom , QString prenom , QDate date_naissance , QString poste , QString sexe , QString email, QString numero_telephone , QDate date_embauche , QDate fin_contrat )
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date_naissance;
    this->poste=poste;
    this->sexe=sexe;
    this->email=email;
    this->date_embauche=date_embauche;
    this->fin_contrat=fin_contrat;
    this->numero_telephone=numero_telephone;
}
int Employe::getid()
{
    return id;
}
QString Employe::getnom()
{
    return nom;
}
QString Employe::getprenom()
{
    return prenom;
}
QString Employe::getsexe()
{
    return sexe;
}
QDate Employe::getdate_naissance()
{
    return date_naissance;
}
QDate Employe::getdate_embauche()
{
    return date_embauche;
}
QString Employe::getposte()
{
    return poste;
}
QString Employe::getemail()
{
    return email;
}
QString Employe::getnumero_telephone()
{
    return numero_telephone;
}

void Employe::setid(int id)
{
    this->id=id;
}

void Employe::setnom(QString nom)
{
    this->nom=nom ;
}

void Employe::setprenom(QString prenom)
{
    this->prenom=prenom;
}

void Employe::setdate_naissance(QDate date_naissance)
{
    this->date_naissance=date_naissance ;
}

void Employe::setnumero_telephone(QString numero_telephone)
{
    this->numero_telephone=numero_telephone ;
}

void Employe::setsexe(QString sexe)
{
    this->sexe=sexe ;
}

void Employe::setdate_embauche(QDate date_embauche)
{
    this->date_embauche=date_embauche ;
}

void Employe::setposte(QString poste)
{
    this->poste=poste ;
}

void Employe::setemail(QString email)
{
    this->email=email ;
}

void Employe::setfin_contrat(QDate fin_contrat)
{
    this->fin_contrat=fin_contrat ;
}

bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GESTION_EMPLOYÉ(ID, NOM, PRÉNOM, DATE_NAISSANCE, EMAIL, NUMÉRO_TELEPHONE, SEXE, POSTE, DATE_EMBAUCHE, FIN_CONTRAT) "
                        "VALUES (:ID, :NOM, :PRENOM, :DATE_NAISSANCE, :EMAIL, :NUMERO_TELEPHONE, :SEXE, :POSTE, :DATE_EMBAUCHE, :FIN_CONTRAT)");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":DATE_NAISSANCE",date_naissance);
    query.bindValue(":EMAIL",email);
    query.bindValue(":NUMERO_TELEPHONE",numero_telephone);
    query.bindValue(":SEXE",sexe);
    query.bindValue(":POSTE",poste);
    query.bindValue(":DATE_EMBAUCHE",date_embauche);
    query.bindValue(":FIN_CONTRAT",fin_contrat);
    return query.exec();
}

bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from GESTION_EMPLOYÉ where id=:id" );
    query.bindValue(":id",id);
    return query.exec();
}


QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT id, nom, prénom,poste FROM GESTION_EMPLOYÉ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Poste"));
    return model;
}

bool Employe::modifier(int nid)
{
    QSqlQuery query;
    query.prepare("UPDATE GESTION_EMPLOYÉ SET nom=:nom, prénom=:prenom, date_naissance=:date_naissance, email=:email, numéro_telephone=:numero_telephone, sexe=:sexe, poste=:poste, date_embauche=:date_embauche, fin_contrat=:fin_contrat WHERE id=:id");
    query.bindValue(":id",nid);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":email",email);
    query.bindValue(":numero_telephone",numero_telephone);
    query.bindValue(":sexe",sexe);
    query.bindValue(":poste",poste);
    query.bindValue(":date_embauche",date_embauche);
    query.bindValue(":fin_contrat",fin_contrat);

    return query.exec();
}
