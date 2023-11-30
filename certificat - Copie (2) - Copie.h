#ifndef CERTIFICAT_H
#define CERTIFICAT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>

class Certificat
{
public:
    Certificat();
    Certificat (int ,QString,QDate,QString);
    int getid();
    QDate getdate();
    QString gettype();
    QString getduree();
   void setduree(QString);
    void setid(int);
    void setdate(QDate);
    void settype(QString);
    bool ajouter();
    bool supprimer(int);
   Certificat chercherParDate(const QDate &date);

   QSqlQueryModel* afficher();
   QSqlQueryModel* afficher1();
   bool idExists(int id);
   bool modifier(int nid,QDate date,QString type,QString duree);


private:
    int id;
   QString type;
   QDate date;
   QString duree;
};

#endif // CERTIFICAT_H
