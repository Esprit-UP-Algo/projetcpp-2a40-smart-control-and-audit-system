#ifndef FORMATION_H
#define FORMATION_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
class formation
{
public:
    formation();
    formation(int,QString,QString,QDate,QDate,QString,int);
    int getIDFOR();
    QString getype();
    QString getduree();
    QString getformateur();
    QDate getdebut();
    QDate getfin();
    int getnbplace();


    void setIDFOR(int);
    void settype(QString);
    void setduree(QString);
    void setformateur(QString);
    void setdebut(QDate);
    void setfin(QDate);
    void setnbplace(int);

    bool ajouter();
   QSqlQueryModel* afficher();
   QSqlQueryModel* tri();
bool supprimer(int);
bool idExists(int id);
bool modifier(int IDFOR,QString formateur,QString type_de_formation,QString duree,QDate date_de_debut,QDate date_de_fin,int nb_place);


private:
   int IDFOR ;
  QString TYPE_DE_FORMATION;
  QString DUREE_DE_LA_FORMATION;
  QString FORMATEUR;
  QDate DATE_DE_DEBUT;
  QDate DATE_DE_FIN;
 int NB_PLACE;

};

#endif // FORMATION_H
