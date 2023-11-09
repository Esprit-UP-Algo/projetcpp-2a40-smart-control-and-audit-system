#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
Inspection *intrr=new Inspection;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {   intrr->show();
        QMessageBox::critical(nullptr, QObject::tr("Base de donner est : OUVERTE"),
                    QObject::tr("Connexion Réussie.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("la base de données N'EST PAS OUVERTE"),
                    QObject::tr("échec de la connexion.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);



    return a.exec();
}
