#ifndef INSPECTION_H
#define INSPECTION_H
#include <QString>
#include <QSqlQueryModel>
class Inspection
{
public:
    Inspection();
    Inspection(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom ();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    bool supprimer(int);

    QSqlQueryModel* afficher();
private:
    int id ;
    QString nom , prenom ;

};

#endif // INSPECTION_H
