#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "employe.h"
#include <QPushButton>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openajoutButton, &QPushButton::clicked, this, &MainWindow::openajout);
    idsupp = ui->idsupp;
    idsupp->setStyleSheet("font-size: 15px;"
                       "color: #fff; border-radius: 15px; border: 1px solid rgba(51, 66, 255, 0.00);"
                           "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                           "display: flex;"
                           "width: 484px;"
                           "height: 60px;"
                           "padding: 5px 2px;"
                            "padding-left: 15px;"

                           "flex: 0;"

                           "font-family:Arial;");
    ui->table->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openajout()
{
    ajout ajout;
    ajout.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    Employe E1;
    E1.setid(ui->idsupp->text().toInt());
        bool test=E1.supprimer(E1.getid());
        if(test){
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectuée.\nClick Cancel to exit."),QMessageBox::Cancel);
        }
        ui->table->setModel(E.afficher());
}

void MainWindow::on_refresh_clicked()
{
    ui->table->setModel(E.afficher());
}
