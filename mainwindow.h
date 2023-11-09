#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "employe.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>


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
    void on_refresh_clicked();
    void on_openajoutButton_clicked();
    void on_eng_clicked();
    void on_modifier_clicked();    
    void on_return_2_clicked();

    void on_trier_clicked();

    void on_recherch_editingFinished();

    void on_pdf_clicked();
    int countType(const QString&);


    void on_STATISTIQUE_clicked();

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
    QLineEdit *email;
    QLineEdit *num;
    QComboBox *poste;
    QDateEdit *date1;
    QDateEdit *date2;
    QLineEdit *recherch;
};
#endif // MAINWINDOW_H
