#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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




    return a.exec();
}

