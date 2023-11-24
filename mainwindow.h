#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "employe.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QLabel>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>



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
    void on_pushButton_4_clicked();
    //void on_refresh_clicked();
    void on_openajoutButton_clicked();
    void on_eng_clicked();
    void on_modifier_clicked();    
    void on_return_2_clicked();
    void on_trier_clicked();
    void on_pdf_clicked();
    int countType(const QString&);
    void on_STATISTIQUE_clicked();
    void on_texte_recherche_textChanged(const QString &text);
    bool eventFilter(QObject *obj, QEvent *event);  
    void on_chatt_clicked();
    void on_return_3_clicked();

    void on_temps_clicked();

    void on_return_4_clicked();

    void on_pushButton_5_clicked();
    void afficherchat();
    void on_sendmsg_editingFinished();
    void updateTime();
    void saveEmployeeTime(const QDateTime &startTime, const QDateTime &finishTime);
    void openImageDialog();




    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
    QPushButton *openajoutButton;
    Employe E;
    QLineEdit *id;
    QLineEdit *nom;
    QLineEdit *prenom;
    QDateEdit *date;
    QComboBox *sexe;
    QComboBox *idsup;
    QComboBox *tempsss;
    QLineEdit *email;
    QLineEdit *num;
    QComboBox *poste;
    QDateEdit *date1;
    QDateEdit *date2;
    QLineEdit *recherch;


};
#endif // MAINWINDOW_H
