#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "employe.h"

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
    void openajout();

    void on_pushButton_4_clicked();

    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *openajoutButton;
    QLineEdit *idsupp;
    Employe E;
};
#endif // MAINWINDOW_H
