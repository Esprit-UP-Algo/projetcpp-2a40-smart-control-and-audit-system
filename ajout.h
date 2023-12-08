#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>

namespace Ui {
class ajout;
}

class ajout : public QDialog
{
    Q_OBJECT

public:
    explicit ajout(QWidget *parent = nullptr);
    ~ajout();

private slots:
    void on_eng_clicked();

    void on_modifier_clicked();

private:
    Ui::ajout *ui;
    QLineEdit *id;
    QLineEdit *nom;
    QLineEdit *prenom;
    QDateEdit *date;
    QComboBox *sexe;
    QLineEdit *email;
    QLineEdit *num;
    QLineEdit *poste;
    QDateEdit *date1;
    QDateEdit *date2;

};

#endif // AJOUT_H
