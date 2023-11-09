#ifndef INSPECTION_H
#define INSPECTION_H

#include <QString>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QDate>
#include <QMainWindow>
#include<QIntValidator>
#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QHeaderView>
#include<QPushButton>
#include<QLineEdit>
#include<QPixmap>
#include<QMessageBox>
#include<QTableView>
#include<QCheckBox>
#include<QComboBox>
#include <QGraphicsBlurEffect>
#include <QVBoxLayout>
#include <QDateEdit>
#include<QPrinter>
#include<QTextDocument>
#include<QFileDialog>
class QLabel;
class QPushButton;
class QLineEdit;
class QPixmap;

class Inspection : public QMainWindow
{
    Q_OBJECT
    int IDIN;
    QDate date;
    float frais;
    QString methode;
     QString etat;
      QString type;
public:
    Inspection(QWidget *parent=nullptr);
    Inspection(int,QDate,float,QString,QString,QString);
    int getIDIN(){return IDIN;}
    QString getEtat(){return etat;}
    QString getMethode(){ return methode;}
    QString getType(){return type;}
    float getFrais(){ return frais;}
    QDate getDate(){ return date;}

    void setIDIN(int val){IDIN=val;}
    void setDate(QDate val){date=val;}
    void setFrais(float val){frais=val ;}
    void setMethode(QString val){methode=val ;}
    void setType(QString val){type=val ;}
    void setEtat(QString val){etat=val ;}

    void show_ajouter();
    void show_supprimer();
    void show_moddifier();
    void show_statistique();
    void show_recherche();
    void enregistrer();
    bool ajouter();
    bool supprimer(int idn);
    void confirmer_supp();
    bool update_inspection(int id );
    void modifier_ins();
    void remplir_combobox(QComboBox * id_a_supprimee);
    void Recherher();
    QSqlQueryModel* afficher();
    void showpdf();



    // all the labels
    QLabel *main_label;
    QLabel *logo_label;
    QLabel *attribut[6] ;
    QLabel *lab_enregistrer;
    QLabel *lab_supp;
    QLabel *lab_id_supprimee;
    QLabel *attribut_supp;
    QLabel *lab_modif[6];
    QLabel *attribut_modif[6];
    QLabel *lab_button_modif;
    QLabel *lab_statistique;
    QLabel *mokabra;
    QLabel *lab_nom_attribut_recherche;
    QLabel *layout_zonesaisie_rech;
    QLabel *search_lab;



         /// box
    QLabel *ajout_box;
    QLabel *supprime_box;
    QLabel *modifier_box;
    QLabel *lab_saisir[6];
    QLabel *recherche_box;


    //Push button
    QPushButton *btn_acceuil;
    QPushButton *btn_show_box_ajout;
    QPushButton *btn_show_box_supprime;
    QPushButton *btn_show_box_modifier;
    QPushButton *btn_show_box_TRIE;
    QPushButton *btn_show_box_STATITIQUE;
    QPushButton *btn_menu[6];
    QPushButton *Enregistrer;
    QPushButton *Supprimer;
    QPushButton *modifier;
    QPushButton *btn_recherche;
    QPushButton *search;
    QPushButton *PDF;




    //QFrames
    QFrame *list_inspection;
    QFrame *view_recheche;

    //QLinEdit
    QLineEdit *information_dajout[2];
    QLineEdit *id_supp;
    QLineEdit *line_idin;
    QLineEdit *line_modif[6];
    QLineEdit *lab_recherche;

    //QTableView
    QTableView *list;//pour l'affich

    //QCheckBox
    QCheckBox *type_audit[5];

    //Qcombokbox
    QComboBox *combo_ajout[4];
    QComboBox *combo_modifier[4];
    QComboBox *id_a_supprimee;

    //QdateEdit
    QDateEdit  *date_edit;
    QDateEdit  *date_modif;



};

#endif // INSPECTION_H
