#include "inspection.h"

Inspection::Inspection(int i,QString d ,float f,QString m, QString t,QString e)
{
    IDIN=i;
    date=d;
    frais=f;
    methode=m;
    etat=e;
    type=t;
}
Inspection::Inspection(QWidget *parent)
    :QMainWindow(parent)
{
    this->resize(1920,1061);
    QPixmap pic(":/image/Desktop (2).png");
    QPixmap pic_text(":/image/unnamed (1).png");
    QPixmap pic_btnmenu(":/image/Update Layout (1).png");
    QPixmap pic_ajout(":/image/ajoutUpdateLayout.png");
     QPixmap pic_supprim(":/image/ajoutUpdateLayout.png");
    QPixmap cadre(":/image/unnamed.png");
    QPixmap pic_a(":/image/List.png");
    QPixmap button_enregistrement(":/image/Button.png");

    mainlab=new QLabel(this);
    mainlab->setPixmap(pic);
    mainlab->setFixedSize(pic.size());

    labtext=new QLabel(this);
    labtext->setPixmap(pic_text);
    labtext->setFixedSize(pic_text.size());
    labtext->move(165,180);

    menu_btn=new QLabel(this);
    menu_btn->setPixmap(pic_btnmenu);
    menu_btn->setGeometry(1330,164,pic_btnmenu.width(),pic_btnmenu.height());

    for (int i=0;i<5;i++) {
        btn[i]=new QPushButton(this);
        btn[i]->setStyleSheet("background:transparent;border:none;font-size:20px;color:white;");
        btn[i]->setFixedSize(401,127);
        btn[i]->move(1380,300+(i*90));
    }
    btn[0]->setText("Gestion e");
    btn[1]->setText("Gestion e");
    btn[2]->setText("Gestion e");
    btn[3]->setText("Gestion e");
    btn[4]->setText("Gestion e");

    for (int i=0;i<5;i++) {
        lab[i]=new QLabel(btn[i]);
        lab[i]->setPixmap(cadre);
        lab[i]->setFixedSize(401,127);
    }
    list_inspection=new QFrame(this);
    list_inspection->setGeometry(28,303,1219,514);
    list=new QTableView(list_inspection);
    list->setGeometry(90,0,1100,450);
    list->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                            "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                            "display: flex;"
                            "width: 484px;"
                            "height: 60px;"
                            "padding: 20px 16px;"
                            "align-items: center;"
                            "spacing: 24px;"
                            "flex: 0;");
    list->setModel(afficher());
    Ajouter_boxx_btn=new QPushButton("AJOUTER",this);
    Ajouter_boxx_btn->setGeometry(200,811,110,43);
    Ajouter_boxx_btn->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

    Supprimer_boxx_btn=new QPushButton("SUPPRIMER",this);
    Supprimer_boxx_btn->setGeometry(450,811,110,43);
    Supprimer_boxx_btn->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

    ajout_box = new QLabel(this);
    ajout_box->setPixmap(pic_ajout);
    ajout_box->setGeometry(580,200,pic_ajout.width(),pic_ajout.height());
    ajout_box->hide();

    supp_box = new QLabel(this);
    supp_box->setPixmap(pic_supprim);
    supp_box->setGeometry(580,200,pic_supprim.width(),pic_supprim.height());
    supp_box->hide();
    id_supp =new QLineEdit(supp_box);
    id_supp->setGeometry(500,50,pic_a.width(),pic_a.height());
    id_supp->setPlaceholderText("Entrez votre identifant ");
    id_supp->setStyleSheet("background:transparent;border:none;font-size:20px;color:white ");

    id_supp_lab=new QLabel(id_supp);
    id_supp_lab->setPixmap(pic_a);

    text_supp=new QLabel("Identifiant",supp_box);
    text_supp->setGeometry(250,50,150,50);
    text_supp->setStyleSheet("font-size:20px;color:white");


    for (int i=0;i<6;i++) {
        info_edit[i]=new QLineEdit(ajout_box);
        info_edit[i]->setStyleSheet("background:transparent;border:none;font-size:20px;color:white ");
        info_edit[i]->setGeometry(500,50+(i*70),pic_a.width(),pic_a.height());
    }
    info_edit[0]->setPlaceholderText("Entrez votre identifant");
    info_edit[1]->setPlaceholderText("Entrez votre Date du mission");
    info_edit[2]->setPlaceholderText("Entrez votre les frais du mission");
    info_edit[3]->setPlaceholderText("Entrez votre la methode du mission");
    info_edit[4]->setPlaceholderText("Entrez votre l'etat du mission");
    info_edit[5]->setPlaceholderText("Entrez votre le type  du mission");

    for (int i=0;i<6;i++) {
        edt[i]= new QLabel(info_edit[i]);
        edt[i]->setPixmap(pic_a);
    }
    for (int i=0;i<6;i++) {
        lab_edit[i]=new QLabel(ajout_box);
        lab_edit[i]->setGeometry(250,50+(i*70),150,50);
        lab_edit[i]->setStyleSheet("font-size:20px;color:white");
    }
    lab_edit[0]->setText("Identifiant");
    lab_edit[1]->setText("date du mission");
    lab_edit[2]->setText("frais du mission");
    lab_edit[3]->setText("methode du mission");
    lab_edit[4]->setText("etat du mission");
    lab_edit[5]->setText("type du mission");


    Enregistrer=new QPushButton(ajout_box);
    Enregistrer->setGeometry(500,500,button_enregistrement.width(),button_enregistrement.height());
    Enregistrer->setStyleSheet("background:transparent");
    lab_enr=new QLabel(Enregistrer);
    lab_enr->setPixmap(button_enregistrement);

    Supprimer=new QPushButton(supp_box);
    Supprimer->setGeometry(500,500,button_enregistrement.width(),button_enregistrement.height());
    Supprimer->setStyleSheet("background:transparent");
    lab_supp=new QLabel(Supprimer);
    lab_supp->setPixmap(button_enregistrement);

    connect(Ajouter_boxx_btn, &QPushButton::clicked, this, &Inspection::show_ajouter);
    connect(Supprimer_boxx_btn, &QPushButton::clicked, this, &Inspection::show_supprimer);
    connect(Enregistrer, &QPushButton::clicked, this, &Inspection::enregistrer);
    connect(Supprimer, &QPushButton::clicked, this, &Inspection::confirmer_supp);
}
void Inspection::show_ajouter()
{
    if (ajout_box->isHidden() || supp_box->isWindow()) {
        ajout_box->show();
        supp_box->hide();
    }
    else ajout_box->hide();
}
void Inspection::show_supprimer()
{
    if (supp_box->isHidden()|| ajout_box->isWindow()) {
        supp_box->show();
        ajout_box->hide();
    }
    else supp_box->hide();
}
void Inspection::enregistrer()
{
    bool test=false;
    int id=info_edit[0]->text().toInt();
    QString date = info_edit[1]->text();
    float frais = info_edit[2]->text().toFloat();
    QString methode = info_edit[3]->text();
    QString etat = info_edit[4]->text();
    QString type = info_edit[5]->text();
    Inspection i(id,date,frais,methode,etat,type);
    test=i.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout successful.\n""Click cancel to exit."),QMessageBox::Cancel);
        list->setModel(i.afficher());
    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout failed.\n""Click cancel to exit."),QMessageBox::Cancel);
       }

}
bool Inspection::ajouter ()
{
    QSqlQuery query;
    QString id_string=QString:: number (IDIN);
    QString frait_String=QString:: number (frais);

          query.prepare("INSERT INTO INSPECTION (IDIN, DATE_MISSION,FRAIT_MISSION, METHODE,ETAT,TYPE_MISSION) "
                        "VALUES (:id, :foredate,:surfrais,:surmethode,:suretat,:surtype)");
          query.bindValue(":id", id_string );
          query.bindValue(":foredate", date);
          query.bindValue(":surfrais", frait_String);
          query.bindValue(":surmethode", methode);
          query.bindValue(":suretat", etat);
          query.bindValue(":surtype", type);
          return query.exec();
}
QSqlQueryModel * Inspection :: afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM INSPECTION");
    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr( "frais"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr( "etat"));*/

    return model;
}
bool Inspection::supprimer(int idn)
{
    QSqlQuery query;
         query.prepare("DELETE FROM INSPECTION WHERE IDIN=:id");
         query.bindValue(":id", idn);

        return query.exec();
}
void Inspection::confirmer_supp()
{
    Inspection I1;
        I1.setIDIN(id_supp->text().toInt());
        bool test = I1.supprimer(I1.getIDIN());
        if(test)
        {
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression successful.\n""Click cancel to exit."),QMessageBox::Cancel);
            list->setModel(I1.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression failed.\n""Click cancel to exit."),QMessageBox::Cancel);
        }
}

