#ifndef INSPECTION_H
#define INSPECTION_H

#include <QString>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QDate>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QPixmap>
#include<QMessageBox>
#include<QTableView>
class QLabel;
class QPushButton;
class QLineEdit;
class QPixmap;

class Inspection : public QMainWindow
{
    Q_OBJECT
public:
    Inspection(QWidget *parent=nullptr);
    Inspection(int,QString,float,QString,QString,QString);
    int getIDIN(){return IDIN;}
    QString getEtat(){return etat;}
    QString getMethode(){ return methode;}
    QString getType(){return type;}
    float getFrais(){ return frais;}
    QString getDate(){ return date;}

    void setIDIN(int val){IDIN=val;}
    void setDate(QString val){date=val;}
    void setFrais(float val){frais=val ;}
    void setMethode(QString val){methode=val ;}
    void setType(QString val){type=val ;}
    void setEtat(QString val){etat=val ;}


public :
    void show_ajouter();
    void show_supprimer();
    void enregistrer();
    void confirmer_supp();
    bool ajouter();
    bool supprimer(int);
QSqlQueryModel* afficher();
private:
    int IDIN;
    QString date;
    float frais;
    QString methode;
     QString etat;
      QString type;

    QLabel *mainlab;
    QLabel *labtext;
    QLabel *menu_btn;
    QLabel *lab[5];
    QPushButton *btn[5];

    QLabel *ajout_box ;
    QLabel *supp_box;
    QPushButton *Ajouter_boxx_btn;
    QPushButton *Supprimer_boxx_btn;
    QPushButton *Enregistrer;
    QPushButton *Supprimer;
    QLabel *lab_enr ;
    QLabel *lab_supp;

    QLineEdit *id_supp;
    QLabel *id_supp_lab;
    QLabel *text_supp;

    QLabel *lab_edit[6];
    QLabel *edt[6];
    QLineEdit *info_edit[6];

    QFrame *list_inspection;
    QTableView *list;//pour l'affich
};

#endif // INSPECTION_H
