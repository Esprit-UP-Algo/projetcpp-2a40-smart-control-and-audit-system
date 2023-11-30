#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "inspection.h"
#include "connection.h"
#include "openexcel.h"
#include "notepad.h"
#include "arduino.h"
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

   // void on_Notepad_ecrire_clicked();

  //  void on_NOtepad_afficher_clicked();



  //  void on_pushButton_enregistre_notepad_clicked();


    void on_pushButton_annuler_m_clicked();


    //void on_pushButton_enregistre_notepad_clicked();

  //  void on_fontComboBox_currentFontChanged(const QFont &f);



    void on_G_Inspection_test_clicked();
    bool modifier_presence_employe(int id,QString PRECENSE);
    bool modifier_presence_login(QString admin,QString PRECENSE);


    void on_login_connecter_clicked();

    void on_pushButton_TT_clicked();



    //void on_pushButton_ouvrir_clicked();

    void on_login_hide_clicked();

    void on_login_show_clicked();



private:
    QLabel * blasa;
    Ui::MainWindow *ui;
    QByteArray data;
    arduino A;
     Notepad *notepad;

};

/*class Notepad
{

    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();
    QString currentFile = "";

private slots:

};*/


#endif // MAINWINDOW_H