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
#include <QBrush>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include<QPrinter>
#include<QTextDocument>
#include<QFileDialog>
#include <QVariant>
#include<QPieSeries>
#include<QSortFilterProxyModel>
#include <QtNetwork>
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
      Inspection();
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

      bool ajouter();
      bool function_search(int );
      QSqlQueryModel* afficher();
       bool supprimer(int idn);
       void Recherher();
       bool modifier(int IDIN, QDate date,float frais, QString methode, QString etat,QString type);
       void calculateInspectionsPerMonth();


};



#endif // INSPECTION_H
