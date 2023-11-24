#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formation.h"
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>


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

    void on_pushButton_clicked();

    void on_bt_return_clicked();

    void on_ajouter_Cancel_clicked();

    void on_ajouter_Confirm_clicked();

    void on_supprimer_clicked();
    
    void on_ajouter_clicked();

    void on_bt_modifier_clicked();

    void on_mconfirm_clicked();

    void on_bt_mreturn_clicked();

    void on_TRI_clicked();

 void on_texte_recherche_textChanged(const QString &text);

    void on_refresh_clicked();

    void on_login_connecter_clicked();

    void on_creer_confirmer_clicked();

    void on_login_show_clicked();

    void on_PDF_clicked();

    void STATISTIQUE();
    int countType(const QString& );


void on_mannuler_clicked();



void on_hide_clicked();

void on_login_hide_clicked();

void on_acceuil_gestion_employe_clicked();

void on_acceuil_gestion_entreprise_clicked();

void on_acceuil_gestion_inspection_clicked();

void on_acceuil_gestion_certificat_clicked();

void on_acceuil_gestion_formation_clicked();

void on_gestion_formation_deconnecter_clicked();

void on_bt_historique_clicked();

void onComboBoxhistorique(int index);

void on_pushButton_2_clicked();

void Notification();

QString Message_Notification();
void on_creer_return_clicked();

void on_notification_system();

void on_QUITTER_clicked();

void on_FULLSCREEN_clicked();

void on_yt_clicked();

private:
    Ui::MainWindow *ui;
    formation f;
    void init();
    void on_mid_currentIndexChanged(int index);

};
#endif // MAINWINDOW_H
