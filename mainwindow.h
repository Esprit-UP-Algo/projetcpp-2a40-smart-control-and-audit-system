#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"entreprise.h"
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

private:
    Ui::MainWindow *ui;
    Entreprise e;
};
#endif // MAINWINDOW_H
