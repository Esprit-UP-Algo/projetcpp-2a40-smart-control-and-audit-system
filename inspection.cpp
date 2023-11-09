#include "inspection.h"
#include<QDebug>
Inspection::Inspection(int i,QDate d ,float f,QString m, QString t,QString e)
{
    IDIN=i;
    date=d;
    frais=f;
    methode=m;
    etat=e;
    type=t;
}

void Inspection::show_ajouter()
{
    if (ajout_box->isHidden() || supprime_box->isWindow()|| modifier_box->isWindow()||recherche_box->isWindow()) {
      //fonction blur
        /* QVBoxLayout layout(this);
        QGraphicsBlurEffect blurEffect;
            blurEffect.setBlurRadius(10);  // Adjust the blur radius as needed
            this->setGraphicsEffect(&blurEffect);
            layout.addWidget(ajout_box);*/
        ajout_box->show();
        supprime_box->hide();
        modifier_box->hide();
        recherche_box->hide();

    }
    else ajout_box->hide();
}

void Inspection::show_supprimer()
{
    if (supprime_box->isHidden()|| (ajout_box->isWindow()|| modifier_box->isWindow() )) {
        supprime_box->show();
        ajout_box->hide();
        modifier_box->hide();
        recherche_box->hide();
        remplir_combobox(id_a_supprimee);
    }
    else supprime_box->hide();
}

void Inspection::show_moddifier()
{
    if (modifier_box->isHidden()|| (ajout_box->isWindow()|| supprime_box->isWindow() || recherche_box->isWindow())) {
        modifier_box->show();
        ajout_box->hide();
        supprime_box->hide();
        recherche_box->hide();
    }
    else modifier_box->hide();
}

void Inspection::show_statistique()
{
    if (lab_statistique->isHidden()) {
        lab_statistique->show();

    }
    else lab_statistique->hide();
}

void Inspection :: show_recherche()
{
    if (recherche_box->isHidden()|| (ajout_box->isWindow() || supprime_box->isWindow() || modifier_box ->isWindow())) {

        recherche_box->show();
        ajout_box->hide();
        supprime_box->hide();
        modifier_box->hide();
    }
    else
    {recherche_box->hide();}
}
void Inspection::Recherher()
{
    QString id=lab_recherche->text();


             QSqlQueryModel* searchModel = new QSqlQueryModel();
             searchModel->setQuery("SELECT * FROM INSPECTION WHERE IDIN LIKE '%" + id + "%'");

             if (searchModel->rowCount() > 0) {

                 list->setModel(searchModel);


                 QHeaderView* headerView = list->horizontalHeader();
                 headerView->setSectionResizeMode(QHeaderView::Stretch);
             } else {

                 QMessageBox::information(this, "Search Result", "camion does not exist.");
             }
}

bool Inspection::ajouter ()
{
    QSqlQuery query;
    QString id_string=QString:: number (IDIN);
    QString frait_String=QString:: number (frais);
    QString  date_String= date.toString("yyyy-MM-dd");
        query.prepare("INSERT INTO INSPECTION (IDIN, DATE_MISSION,FRAIT_MISSION, METHODE,ETAT,TYPE_MISSION) "
                        "VALUES (:id, :foredate,:surfrais,:surmethode,:suretat,:surtype)");
          query.bindValue(":id", id_string );
          query.bindValue(":foredate", date_String);
          query.bindValue(":surfrais", frait_String);
          query.bindValue(":surmethode", methode);
          query.bindValue(":suretat", etat);
          query.bindValue(":surtype", type);
          return query.exec();
}

void Inspection::enregistrer()
{
    bool test=false;
    int id=information_dajout[0]->text().toInt();
    float frais = information_dajout[1]->text().toFloat();
    QDate date = date_edit->date();
\
    QString methode = combo_ajout[1]->currentText();//methode
    QString etat = combo_ajout[2]->currentText();//etat
    QString type = combo_ajout[3]->currentText();//type

    Inspection i(id,date,frais,methode,etat,type);
    test=i.ajouter();
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout Réussi.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
       list->setModel(i.afficher());
       remplir_combobox(id_a_supprimee);
    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Échec de l'Ajout.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
       }
}

QSqlQueryModel * Inspection :: afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM INSPECTION ");
             // model->setQuery("SELECT IDIN,DATE_MISSION,FRAIT_MISSION,ETAT FROM INSPECTION  ");
   /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr( "frais"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr( "etat"));*/
    return model;
}


 void Inspection::remplir_combobox(QComboBox *id_a_supprimee )
 {
     QSqlQuery query;
                       id_a_supprimee->clear();
                           query.exec("SELECT IDIN FROM INSPECTION");
                           while (query.next()) {
                               int id = query.value(0).toInt();
                               id_a_supprimee->addItem(QString::number(id));}
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
        I1.setIDIN(id_a_supprimee->currentText().toInt());
        bool test = I1.supprimer(I1.getIDIN());
        if(test)
        {
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression reussi.\n""Click cancel to exit."),QMessageBox::Cancel);
            list->setModel(I1.afficher());
            remplir_combobox(id_a_supprimee);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Echec du Suppression .\n""Click cancel to exit."),QMessageBox::Cancel);
        }
}
bool Inspection :: update_inspection(int id )
{
    QSqlQuery query;
    QString frait_String=QString:: number (frais);
    QString  date_String= date.toString("yyyy-MM-dd");
    query.prepare("UPDATE INSPECTION SET IDIN=:id, DATE_MISSION =:dt ,FRAIT_MISSION=:fr, METHODE=:m,ETAT=:e,TYPE_MISSION=:t  where IDIN=:id");
    query.bindValue(":id",id);
    query.bindValue(":dt",date_String);
    query.bindValue(":fr",frait_String);
    query.bindValue(":m",methode);
    query.bindValue(":e",etat);
    query.bindValue(":t",type);

    return query.exec();
}
void Inspection ::modifier_ins()
{

    int id=line_modif[0]->text().toInt();
    QDate date = date_modif->date();
    float frais = line_modif[1]->text().toFloat();

    QString methode = combo_modifier[1]->currentText();//methode
    QString etat = combo_modifier[2]->currentText();//etat
    QString type = combo_modifier[3]->currentText();//type

    Inspection i(id,date,frais,methode,etat,type);

    bool test= i.update_inspection(i.getIDIN());
    if(test)
    { QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("moddi Réussi.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
        list->setModel(i.afficher());
    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Échec de la Modification.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
       }
}

Inspection::Inspection(QWidget *parent):QMainWindow(parent)
{
    this->resize(1920,1061);
    QPixmap background(":/images/background.png");
    QPixmap logo(":/images/logo final.png");
    QPixmap layout(":/images/ajoutUpdateLayout.png");
    QPixmap btn_enregistrer(":/images/Button.png");
    QPixmap btn_supprim(":/images/Button_Supp.png");
    QPixmap blasa(":/images/List.png");
    QPixmap btn_modifier(":/images/Button_modifier.png");
    QPixmap pic_statistique(":/images/statistique.png");
    QPixmap pic_mokabra(":/images/Search.png");
    QPixmap pic_btn_recherche(":/images/Button_chercher.png");


    main_label=new QLabel(this);
    main_label->setPixmap(background);
    main_label->setFixedSize(background.size());

    logo_label=new QLabel(this);
    logo_label->setPixmap(logo);
    logo_label->setGeometry(85,55,logo.width(),logo.height());

 ///////////////////////// *** AFFICHAGE *** /////////////////////////

    list_inspection=new QFrame(this);
    list_inspection->setGeometry(28,303,1219,514);
    list=new QTableView(list_inspection);


   // les buttons du menu
    for (int i=0 ;i<6;i++) {
        btn_menu[i]=new QPushButton(this);
        btn_menu[i]->setStyleSheet("background:transparent;border: 2px solid black;");
       // btn_menu[i]->setStyleSheet("background:transparent;border:none");
        btn_menu[i]->setFixedSize(400,86);
        btn_menu[i]->move(1375,200+(94*i));
    }

///////////////////////////// ***  AJOUTER *** /////////////////////////////
   //BUTTON
    btn_show_box_ajout=new QPushButton("AJOUTER",this);
    btn_show_box_ajout->setGeometry(200,840,110,43);
    btn_show_box_ajout->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
  // CREATION DU BOX D'AJOUT
    ajout_box= new QLabel(this);
    ajout_box->setPixmap(layout);
    ajout_box->setGeometry(450,100,layout.width(),layout.height());
    ajout_box->hide();

   // BOX  D'AJOUT
        // Les attributs
        for (int i=0;i<6;i++) {
            lab_saisir[i]=new QLabel(ajout_box);
            lab_saisir[i]->setGeometry(250,50+(i*70),200,50);
            lab_saisir[i]->setStyleSheet("font-size:20px;color:white");
        }
        lab_saisir[0]->setText("Identifiant");
        lab_saisir[2]->setText("Date du mission");
        lab_saisir[1]->setText("Frais du mission");
        lab_saisir[3]->setText("Methode du mission");
        lab_saisir[4]->setText("Etat du mission");
        lab_saisir[5]->setText("Type du mission");

        // zone de saisie
        for (int i=0;i<2;i++) {
            information_dajout[i]=new QLineEdit(ajout_box);
            information_dajout[i]->setStyleSheet("background:transparent;border:none;font-size:20px;color:white ");
            information_dajout[i]->setGeometry(500,50+(i*70),blasa.width(),blasa.height());
        }
        information_dajout[0]->setPlaceholderText("Entrez votre identifant");
        information_dajout[0]->setValidator( new QIntValidator(100, 999999, ajout_box));
        information_dajout[1]->setPlaceholderText("Entrez les frais du mission");

        for (int i=0;i<2;i++) {
            attribut[i]= new QLabel(information_dajout[i]);
            attribut[i]->setPixmap(blasa);
        }
        for (int i=1;i<4;i++) {
            combo_ajout[i] =new QComboBox(ajout_box);
            combo_ajout[i]->setGeometry(500,190+(i*70),blasa.width(),blasa.height());
            combo_ajout[i]->setStyleSheet("background:transparent;border: 2px solid white");
        }

        date_edit =new QDateEdit(ajout_box);
        date_edit->setGeometry(500,190,blasa.width(),blasa.height());
        date_edit->setStyleSheet("background:transparent;border: 2px solid white");

        combo_ajout[1]->addItem("Control sur pièces");//methode
        combo_ajout[1]->addItem("Observation physique ");
        combo_ajout[1]->addItem("Sondage");

        combo_ajout[2]->addItem("NON Acomplie");//etat
        combo_ajout[2]->addItem("Acomplie");

        combo_ajout[3]->addItem("Environnemental");//type
        combo_ajout[3]->addItem("Externe");
        combo_ajout[3]->addItem("Interne");
        combo_ajout[3]->addItem("De Qualite");
        combo_ajout[3]->addItem("Financier");

  /* type_audit[0] =new QCheckBox("Environnemental",ajout_box);
    type_audit[1] =new QCheckBox("Externe",ajout_box);
    type_audit[2] =new QCheckBox("Interne",ajout_box);
    type_audit[3] =new QCheckBox("De Qualite",ajout_box);
    type_audit[4] =new QCheckBox("Financier",ajout_box);
        for (int i=0;i<3;i++) {
            type_audit[i]->move(500,400+(i*20));
            type_audit[i]->setStyleSheet("font-size:20px;color:white");
        }
        for (int i=2;i<5;i++) {
            type_audit[i]->move(750,400+((i-2)*20));
            type_audit[i]->setStyleSheet("font-size:20px;color:white");
        }*/

     //boutton d'eregistrement
        Enregistrer=new QPushButton(ajout_box);
        Enregistrer->setGeometry(500,500,btn_enregistrer.width(),btn_enregistrer.height());
        Enregistrer->setStyleSheet("background:transparent");
        lab_enregistrer=new QLabel(Enregistrer);
        lab_enregistrer->setPixmap(btn_enregistrer);

     connect(btn_show_box_ajout, &QPushButton::clicked, this, &Inspection::show_ajouter);
     connect(Enregistrer, &QPushButton::clicked, this, &Inspection::enregistrer);

///////////////////////////// ***  SUPPRISSION *** /////////////////////////////

    //bouton supprision on THIS
    btn_show_box_supprime=new QPushButton("SUPPRIMER",this);
    btn_show_box_supprime->setGeometry(400,840,110,43);
    btn_show_box_supprime->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

    //box du supprission
    supprime_box=new QLabel(this);
    supprime_box->setPixmap(layout);
    supprime_box->setGeometry(450,100,layout.width(),layout.height());
    supprime_box->hide();

  //  DANS LE BOX  DE SUPPRISSION

    // boutton de supprission
        Supprimer=new QPushButton(supprime_box);
        Supprimer->setGeometry(500,500,btn_enregistrer.width(),btn_enregistrer.height());
        Supprimer->setStyleSheet("background:transparent");
        lab_supp=new QLabel(Supprimer);
        lab_supp->setPixmap(btn_supprim);

    //attribut du supprission
        lab_id_supprimee=new QLabel(supprime_box);
        lab_id_supprimee->move(200,50+70);
        lab_id_supprimee->setStyleSheet("font-size:20px;color:white");
        lab_id_supprimee->setText("Veuilez Saisir l'Identifiant a Supprimer ");

    // zone de saisie
       /*line_idin=new QLineEdit(supprime_box);
        line_idin->setStyleSheet("background:transparent;border:none;font-size:20px;color:white ");
        line_idin->setGeometry(600,50+60,blasa.width(),blasa.height());
        line_idin->setPlaceholderText("Entrez votre identifant");
        line_idin->setValidator( new QIntValidator(100, 999999, supprime_box));
            attribut_supp= new QLabel(line_idin);
            attribut_supp->setPixmap(blasa);*/

        /*QSqlQuery query;
        QString id_string=QString:: number (IDIN);
        QSqlQueryModel *model = new QSqlQueryModel;
              model->setQuery("SELECT IDIN FROM INSPECTION");
              model->setHeaderData(0, Qt::Horizontal, tr("identifiant"));
              query.bindValue(":id", id_string );

        id_a_supprimee->addItem(QString::model);
        while (query.next()) {
                        int id = query.value(0).toInt();
                        id_a_supprimee->addItem(id_string);


        // id_a_supprimee->addItem("aaaaa");
         //id_a_supprimee->addItem("bbbbb");

        // connect(id_a_supprimee, SIGNAL(activated(int)), supprime_box, SLOT(maFonctionDeTraitement(int)));


                     while (query.next()) {
                                     int id = query.value(0).toInt();
                                     id_a_supprimee->addItem(QString::number(id));}*/

        id_a_supprimee = new QComboBox(supprime_box);
        id_a_supprimee->setFixedSize(300,20);
        id_a_supprimee->move(500,300);



    //connect
    connect(btn_show_box_supprime, &QPushButton::clicked, this, &Inspection::show_supprimer);
    connect(Supprimer, &QPushButton::clicked, this, &Inspection::confirmer_supp);


 ///////////////////////////// ***  MODIFIER *** /////////////////////////////

    btn_show_box_modifier=new QPushButton("MODIFIER",this);
    btn_show_box_modifier->setGeometry(200,890,110,43);
    btn_show_box_modifier->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

    // BOX
    modifier_box=new QLabel(this);
    modifier_box->setPixmap(layout);
    modifier_box->setGeometry(450,100,layout.width(),layout.height());
    modifier_box->hide();

    for (int i=0;i<6;i++) {
        lab_modif[i]=new QLabel(modifier_box);
        lab_modif[i]->setGeometry(250,50+(i*70),200,50);
        lab_modif[i]->setStyleSheet("font-size:20px;color:white");
    }
        lab_modif[0]->setText("Identifiant");
        lab_modif[2]->setText("Date du mission");
        lab_modif[1]->setText("Frais du mission");
        lab_modif[3]->setText("Methode du mission");
        lab_modif[4]->setText("Etat du mission");
        lab_modif[5]->setText("Type du mission");

 //zone de saisie
    for (int i=0;i<2;i++) {
        line_modif[i]=new QLineEdit(modifier_box);
        line_modif[i]->setStyleSheet("background:transparent;border:none;font-size:20px;color:white ");
        line_modif[i]->setGeometry(500,50+(i*70),blasa.width(),blasa.height());
        attribut_modif[i]= new QLabel(line_modif[i]);
        attribut_modif[i]->setPixmap(blasa);
    }

    line_modif[0]->setPlaceholderText("Entrez votre identifant");
    line_modif[0]->setValidator( new QIntValidator(100, 999999, modifier_box));
    line_modif[1]->setPlaceholderText("Entrez les frais du mission");

    date_modif =new QDateEdit(modifier_box);
    date_modif->setGeometry(500,190,blasa.width(),blasa.height());
    date_modif->setStyleSheet("background:transparent;border: 2px solid white");

    for (int i=1;i<4;i++) {
        combo_modifier[i] =new QComboBox(modifier_box);
        combo_modifier[i]->setGeometry(500,190+(i*70),blasa.width(),blasa.height());
        combo_modifier[i]->setStyleSheet("background:transparent;border: 2px solid white");
              }

        combo_modifier[1]->addItem("Control sur pièces");//methode
        combo_modifier[1]->addItem("Observation physique ");
        combo_modifier[1]->addItem("Sondage");

        combo_modifier[2]->addItem("NON Acomplie");//etat
        combo_modifier[2]->addItem("Acomplie");

        combo_modifier[3]->addItem("Environnemental");//type
        combo_modifier[3]->addItem("Externe");
        combo_modifier[3]->addItem("Interne");
        combo_modifier[3]->addItem("De Qualite");
        combo_modifier[3]->addItem("Financier");

       modifier= new QPushButton(modifier_box);
       modifier->setGeometry(500,500,btn_enregistrer.width(),btn_enregistrer.height());
       modifier->setStyleSheet("background:transparent");

       lab_button_modif=new QLabel(modifier);
       lab_button_modif->setPixmap(btn_modifier);

   /// int idin=line_modif[0]->text().toInt();
    /* if(recherche(idin))
    {
        QMessageBox::critical(nullptr, QObject::tr("LKITOU?"),
                    QObject::tr("RECHERCHE  Réussie.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }///*/
    //connect

   connect(btn_show_box_modifier, &QPushButton::clicked, this, &Inspection::show_moddifier);
   connect(modifier, &QPushButton::clicked, this, &Inspection::modifier_ins);

 ///////////////////////////// ***  TRIER *** /////////////////////////////
   btn_show_box_TRIE=new QPushButton("TRIER",this);
   btn_show_box_TRIE->setGeometry(600,840,110,43);
   btn_show_box_TRIE->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

 ///////////////////////////// ***  STATISTIQUE *** /////////////////////////////
   btn_show_box_STATITIQUE=new QPushButton("STATISTIQUE",this);
   btn_show_box_STATITIQUE->setGeometry(400,890,150,43);
   btn_show_box_STATITIQUE->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");

   lab_statistique=new QLabel(this);
           lab_statistique->setPixmap(pic_statistique);
           lab_statistique->setGeometry(1330,800,435,212);
           lab_statistique->hide();
    connect(btn_show_box_STATITIQUE,&QPushButton::clicked, this, &Inspection::show_statistique);

 ///////////////////////////// ***  RECHERCHE *** /////////////////////////////
    btn_recherche=new QPushButton ("RECHERCHE",this);
    btn_recherche->setGeometry(800,840,160,43);
    btn_recherche->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");


    mokabra=new QLabel(this);
    mokabra->setPixmap(pic_mokabra);
    mokabra->setGeometry(960,850,pic_mokabra.width(),pic_mokabra.height());

    recherche_box=new QLabel(this);
    recherche_box->setPixmap(layout);
    recherche_box->setGeometry(450,100,layout.width(),layout.height());
    recherche_box->hide();

    //  DANS LE BOX  DE RECHERCHE

    /*view_recheche= new QFrame(recherche_box);
    view_recheche->setGeometry(28,303,1219,514);
     QTableView *view = new QTableView(recherche_box);

     view=new QTableView(view_recheche);
     view->setGeometry(90,40,110,45);
     view->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                             "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                             "display: flex;"
                             "width: 484px;"
                             "height: 60px;"
                             "padding: 20px 16px;"
                             "align-items: center;"
                             "spacing: 24px;"
                             "flex: 0;");

         view->setModel(recherche());*/

    search=new QPushButton(recherche_box);
    search->setGeometry(500,500,btn_enregistrer.width(),btn_enregistrer.height());
    search->setStyleSheet("background:transparent");
    search_lab=new QLabel(search);
    search_lab->setPixmap(pic_btn_recherche);



        lab_nom_attribut_recherche=new QLabel(recherche_box);
        lab_nom_attribut_recherche->setGeometry(250,350,200,50);
        lab_nom_attribut_recherche->setStyleSheet("font-size:20px;color:white");
         lab_nom_attribut_recherche->setText("Identifiant");


    lab_recherche=new QLineEdit(recherche_box);
    lab_recherche->setGeometry(500,350,blasa.width(),blasa.height());
    lab_recherche->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
    lab_recherche->setValidator( new QIntValidator(100, 999999, recherche_box));
    lab_recherche->setPlaceholderText("Veuillez entre l'identifiant a rechercher");

    layout_zonesaisie_rech=new QLabel(lab_recherche);
    layout_zonesaisie_rech->setPixmap(blasa);



         // Adjust the header view as needed
        // QHeaderView *  headerView = view->horizontalHeader();
      //   headerView ->setSectionResizeMode(QHeaderView::Stretch);
    list->setGeometry(90,40,1100,450);
    list->setStyleSheet("color: #FFF; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                            "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"
                            "display: flex;"
                            "width: 500px;"
                            "height: 100px;"
                            "padding: 20px 16px;"
                            "align-items: center;"
                            "spacing: 24px;"
                            "flex: 0;");
    list->setModel(afficher());

    connect(btn_recherche, &QPushButton::clicked, this, &Inspection::show_recherche);
    connect(search, &QPushButton::clicked, this, &Inspection::Recherher);

    ///////////////////////////// ***  PDF *** /////////////////////////////

    PDF= new QPushButton("PDF",this);
    PDF->setGeometry(950,840,160,43);
    PDF->setStyleSheet("background:transparent;border:none;font-size:20px;color:white");
    connect(PDF, &QPushButton::clicked, this, &Inspection::showpdf);
}
void Inspection::showpdf()
{


    // Associez le modèle à votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(list->model());

    if (model) {
        QString content;
        //header
        for (int col = 0; col < model->columnCount(); ++col) {

             content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                }
        content += "\n";
        // Parcourez les données du modèle et ajoutez-les au contenu
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                content += model->data(model->index(row, col)).toString() + "\t";
            }
            content += "\n";
        }

        // Créez un objet QTextDocument et définissez son contenu
        QTextDocument document;
        document.setPlainText(content);

        // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/Beats SQA/Documents", "Fichiers PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            // Créez un objet QPrinter pour générer le PDF.
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Imprimez le document sur le PDF.
            document.print(&printer);

            // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
            QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
        }
    }
}
