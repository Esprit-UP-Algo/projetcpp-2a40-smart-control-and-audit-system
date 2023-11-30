#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "certificat.h"
#include <QMainWindow>
#include <QMessageBox>
#include<QSqlTableModel>
#include<QFileDialog>
#include<QTextDocument>
#include <QPrinter>
#include <QPieSeries>
#include <QChart>
#include <QChartView>


#include<QObject>
#include "certificat.h"
#include <QIntValidator>
#include "connection.h"
#include<QMessageBox>
#include<QSqlTableModel>
#include<QFileDialog>
#include<QTextDocument>
#include <QPrinter>
#include <QPieSeries>


#include<QGraphicsDropShadowEffect>
#include<QStackedWidget>
#include <QApplication>
#include <QLineEdit>
#include <QWidget>
#include <QPropertyAnimation>
#include <QPalette>
#include<QMessageBox>
#include<QObject>
#include<QIntValidator>
#include<QSqlTableModel>
#include <iostream>
#include <QTableView>
#include <QPropertyAnimation>
#include <QLinearGradient>
#include <QBrush>
#include<QAbstractTableModel>
#include <cstdlib>
#include <QPrinter>
#include <QTextDocument>
#include<iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_label_2_linkActivated(const QString &link);

    void on_pb_ajouter_clicked();

    //void on_pushButton_clicked();

    //void on_bt_suiv_clicked();

    void on_bt_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_le_supprimer_clicked();

void imprimerTableau(QTableView *tableView);

    void on_trier_clicked();

    void on_rechercher_clicked();
    void on_refresh_clicked();
    void on_pdf_clicked();
     int countType(const QString& );
    void on_STATISTIQUE_clicked();
    void updateUI(int selectedId);
    void on_bt_modifier_clicked();
    void on_mid_currentIndexChanged(int index);
    void on_modifier_return_clicked();

    void on_modifier_confirmer_clicked();


    void on_pushButton_clicked();



    void onComboBoxhistorique(int index);
    void on_bt_historique_clicked();



    void on_imprimer_clicked();

private:
    Ui::MainWindow *ui;
    Certificat C;

};
#endif // MAINWINDOW_H
