#include "mainwindow.h"
<<<<<<< HEAD

#include <QApplication>
=======
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>

>>>>>>> 1ada1892b7e4863fe749f108f1ea42b5cba70241

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
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
=======
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test){
        w.show();}
    /*QTcpServer server;
        if (!server.listen(QHostAddress::Any, 12345))
        {
            qDebug() << "Server could not start!";
            return -1;
        }

        qDebug() << "Server started on port 12345";

        QObject::connect(&server, &QTcpServer::newConnection, [&]()
        {
            QTcpSocket *socket = server.nextPendingConnection();
            QObject::connect(socket, &QTcpSocket::readyRead, [&]()
            {
                QByteArray data = socket->readAll();
                qDebug() << "Received: " << data;

                // Forward the message to all connected clients
                for (QTcpSocket *client : server.findChildren<QTcpSocket *>())
                {
                    if (client != socket)
                        client->write(data);
                }
            });
        });*/

>>>>>>> 1ada1892b7e4863fe749f108f1ea42b5cba70241



    return a.exec();
}
<<<<<<< HEAD
=======

>>>>>>> 1ada1892b7e4863fe749f108f1ea42b5cba70241
