#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formation.h"
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
    void on_bt_ajouter_clicked();

    void on_pushButton_clicked();

    void on_bt_return_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_Canel_clicked();

    void on_ajouter_Confirm_clicked();

    void on_supprimer_clicked();

    //void on_supprimer_clicked();
    
private:
    Ui::MainWindow *ui;
    formation f;
};
#endif // MAINWINDOW_H
