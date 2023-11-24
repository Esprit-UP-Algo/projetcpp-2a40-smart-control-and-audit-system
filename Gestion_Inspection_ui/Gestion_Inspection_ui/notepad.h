#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QWidget>
#include "ui_mainwindow.h"

class Notepad : public QWidget
{
    Q_OBJECT
public:
    Notepad(Ui::MainWindow *ui, QWidget *parent = nullptr);

private:
    Ui::MainWindow *ui;
public:
    Notepad();
    void enregistrer_sous();
    void enregistrer();
    void ouvrir();
    void Quitter();
    void Undo();
    void affiche();
    void imprimer();
    void ecrire();

    QLabel * box_Notepad;
    QString currentFile = "";
    QPushButton * enregistrer_notepad;
};

#endif // NOTEPAD_H
