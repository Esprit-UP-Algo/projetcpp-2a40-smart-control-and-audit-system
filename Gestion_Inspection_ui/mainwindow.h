#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "inspection.h"
#include "connection.h"
#include "openexcel.h"
#include "notepad.h"
#include <QApplication>
#include <QMainWindow>
#include <QDate>

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


    void on_G_Inspection_AJOUTER_clicked();

    void on_return_ajouter_clicked();

    void on_ajouter_enregistrer_clicked();

    void on_G_Inspection_SUPPRIMER_clicked();

    void on_G_Inspection_TRI_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);



    void on_pushButton_modifier_clicked();

    void on_G_Inspection_MODIFIER_clicked();


    void on_pushButton_pdf_clicked();

    void on_G_Inspection_REFRESH_clicked();

    //void on_G_Inspection_STATISTIQUE_clicked();
    int countType(const QString& type);
    void STATISTIQUE();



    void on_G_Inspection_SMS_clicked();

    void on_pushButton_SMS_confirme_clicked();

    void on_return_sms_clicked();

    void on_pushButton_clicked();

    void on_pushButton_return_notepad_clicked();

    void on_G_Inspection_NOTEPAD_clicked();

    //void on_pushButton_enregistre_notepad_clicked();

    void on_Notepad_ecrire_clicked();

    void on_NOtepad_afficher_clicked();



    void on_pushButton_enregistre_notepad_clicked();

private:
    QLabel * blasa;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
