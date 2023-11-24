#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {   w.show();
        QMessageBox::critical(nullptr, QObject::tr("Base de donner est : OUVERTE"),
                    QObject::tr("Connexion Réussie.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("la base de données N'EST PAS OUVERTE"),
                    QObject::tr("échec de la connexion.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);


w.show();
    return a.exec();
}
