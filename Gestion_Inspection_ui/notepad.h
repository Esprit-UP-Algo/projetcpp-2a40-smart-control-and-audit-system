#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QMainWindow>
namespace Ui {
class Notepad;
}

class NotePad : public QMainWindow
{
public:
    NotePad(QWidget *parent = nullptr);
public slots:
    void save();
private:
    Ui::Notepad *ui;
     QString currentFile;
};

#endif // NOTEPAD_H
