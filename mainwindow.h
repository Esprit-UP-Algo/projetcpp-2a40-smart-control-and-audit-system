#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"entreprise.h"
#include"arduino.h"
#include<QMessageBox>
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

    void on_ajouter_clicked();

    void on_enregistrer_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();

    void on_modi_clicked();

    void on_trier_clicked();



    void on_refresh_clicked();

    void on_modifier_btn_clicked();

    void on_retour_clicked();
    void on_mid_currentIndexChanged(int);

    void updateUI(int);
int countEtat(const QString& );
    void on_exportPDFBtn_clicked();
void on_texte_recherche_textChanged(const QString &text);
void on_stat();

void on_mod_enregistrer_clicked();

void on_mod_annuler_clicked();



void on_pushButton_2_clicked();



void on_retour_local_clicked();

void on_email_clicked();

void on_envoyer_clicked();

void on_annuler_email_clicked();



void on_sms_annuler_clicked();

void on_sms_btn_clicked();

void on_sms_envoyer_clicked();
void update_label();

private:
    Ui::MainWindow *ui;
    Entreprise e;
    void remplirComboBoxIdEntreprise();
    QByteArray data;
    Arduino A;
    QString id;

};
#endif // MAINWINDOW_H
