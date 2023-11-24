#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include<QString>
#include<QSqlQueryModel>
class Entreprise
{
public:
    Entreprise();
    Entreprise(int,QString,QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getemail();
    QString getspecialite();
    QString getadresse();
    QString getreception_de_la_demande();
    QString getetat();
    QString getnumero();
    void setid(int);
    void setnom(QString);
    void setemail(QString);
    void setspecialite(QString);
    void setadresse(QString);
    void setreception_de_la_demande(QString);
    void setetat(QString);
    void setnumero(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modi(int);
    bool modifier();
    QSqlQueryModel* tri();
    static Entreprise chercherParId(int id);
    QString obtenirStatistiques();
 private:
    int id;
    QString nom;
    QString email;
    QString specialite;
    QString adresse;
    QString reception_de_la_demande;
    QString etat;
    QString numero;


};

#endif // ENTREPRISE_H
