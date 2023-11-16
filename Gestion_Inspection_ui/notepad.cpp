#include "notepad.h"

#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>


/*NotePad::NotePad(QWidget *parent): QMainWindow(parent),
ui(new Ui::Notepad)
{
  ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}
void NotePad::save()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}*/
