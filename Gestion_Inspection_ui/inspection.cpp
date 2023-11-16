#include "inspection.h"
#include<QDebug>
Inspection::Inspection()
{IDIN=0;
    date=QDate::currentDate();
    frais=0;
    methode="";
    etat="";
    type="";}
Inspection::Inspection(int i,QDate d ,float f,QString m, QString t,QString e)
{
    IDIN=i;
    date=d;
    frais=f;
    methode=m;
    etat=e;
    type=t;
}
bool Inspection::function_search(int id )
{
    QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM INSPECTION WHERE IDIN = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            return count > 0;
        }

        return false;
}
bool Inspection::ajouter ()
{
    QSqlQuery query;
    QString id_string=QString:: number (IDIN);
    QString frait_String=QString:: number (frais);
    QString  date_String= date.toString("yyyy-MM-dd");
        query.prepare("INSERT INTO INSPECTION (IDIN, DATE_MISSION,FRAIT_MISSION, METHODE,ETAT,TYPE_MISSION) "
                        "VALUES (:id, :foredate,:surfrais,:surmethode,:suretat,:surtype)");
          query.bindValue(":id", id_string );
          query.bindValue(":foredate", date_String);
          query.bindValue(":surfrais", frait_String);
          query.bindValue(":surmethode", methode);
          query.bindValue(":suretat", etat);
          query.bindValue(":surtype", type);
          return query.exec();
}
QSqlQueryModel * Inspection :: afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel;

  // model->setQuery("SELECT * FROM INSPECTION ");
              model->setQuery("SELECT IDIN,DATE_MISSION,FRAIT_MISSION,ETAT,TYPE_MISSION FROM INSPECTION  ");

    model->setHeaderData(0, Qt::Horizontal, "IDIN");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_MISSION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr( "FRAIT_MISSION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr( "TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr( "ETAT"));
    ///////// *******************YAAAAAAA HAYEEEEELLAAAAAAAAAAAA*******************//////////////////
    ///////// *******************YAAAAAAA HAYEEEEELLAAAAAAAAAAAA*******************//////////////////
    //////////// *******************YAAAAAAA HAYEEEEELLAAAAAAAAAAAA*******************//////////////////
    //////////// *******************YAAAAAAA HAYEEEEELLAAAAAAAAAAAA*******************//////////////////
    return model;
}


bool Inspection::supprimer(int idn)
{
    QSqlQuery query;
     query.prepare("DELETE FROM INSPECTION WHERE IDIN=:id");
         query.bindValue(":id", idn);

      return query.exec();
}

bool Inspection::modifier(int IDIN, QDate date,float frais, QString methode, QString etat,QString type)
{

        QSqlQuery query;

        query.prepare("UPDATE INSPECTION SET DATE_MISSION=:dt, FRAIT_MISSION=:fr , METHODE=:m , ETAT=:e , TYPE_MISSION=:t  where IDIN=:id");
        query.bindValue(":id",IDIN);
        query.bindValue(":dt",date);
        query.bindValue(":fr",frais);
        query.bindValue(":m",methode);
        query.bindValue(":e",etat);
        query.bindValue(":t",type);
        if (query.exec() && query.next())
            return true;
            else {
                    return false;
            }

}
/*void Inspection::calculateInspectionsPerMonth() {
    QSqlQuery query;
    query.exec("SELECT DATE, IDIN FROM INSPECTION");

    QHash<QString, int> inspectionsPerMonth;

    while (query.next()) {
        QDate date = query.value("DATE").toDate();
        QString monthYear = date.toString("yyyy-MM");
        inspectionsPerMonth[monthYear]++;
    }

    for (auto it = inspectionsPerMonth.begin(); it != inspectionsPerMonth.end(); ++it) {
        qDebug() << "Month: " << it.key() << ", Inspections: " << it.value();
    }
}*/

/*void Inspection ::ecrireDansFichier2(const QString& matricule, const QString& tempsDeMiseAjour)
{
    QString nomFichier = "file:///C:/Users/Beats SQA/Documents/SAVE.txt";
    QFile file(nomFichier);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream <<"MISE A JOUR  :"<< "matricule : " << matricule << ", Temps de l'ajout : " << tempsDeMiseAjour << "\n";
        file.close();
    } else {
        // GÃ©rer les erreurs d'ouverture de fichier
    }
}*/
