#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QDate>
#include<qsqlquerymodel.h>
#include <QSqlQueryModel>

class ImageDelegate;
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QDate,QString,QString,QString,QString,QDate,QDate,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QDate getdate_naissance();
    QString getemail();
    QString getposte();
    QString getnumero_telephone();
    QString getsexe();
    QDate getdate_embauche();
    QDate getfin_contrat();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_naissance(QDate);
    void setemail(QString);
    void setnumero_telephone(QString);
    void setposte(QString);
    void setsexe(QString);
    void setdate_embauche(QDate);
    void setfin_contrat(QDate);

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherc();
    bool modifier(int);
    QSqlQueryModel* afficher1();
    QSqlQueryModel* afficher2();
    QSqlQueryModel* afficher3();
    QSqlQueryModel* afficher4();
    QSqlQueryModel* afficher5();




private:
    QString nom,prenom,email,poste,sexe,numero_telephone,image ;
    int id;
    QDate date_embauche,date_naissance,fin_contrat;
};




#endif // EMPLOYE_H
