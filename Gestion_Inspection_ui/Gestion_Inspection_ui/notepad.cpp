#include "notepad.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


Notepad::Notepad(Ui::MainWindow *ui, QWidget *parent)
    : QWidget(parent), ui(ui)
{
    connect(ui->pushButton_enregistre_notepad, &QPushButton::clicked, this, &Notepad::enregistrer);
    connect(ui->pushButton_ouvrir, &QPushButton::clicked, this,  &Notepad::ouvrir);
    connect(ui->pushButton_Quitter, &QPushButton::clicked, this,  &Notepad::Quitter);
    connect(ui->pushButton_Imprimer, &QPushButton::clicked, this,  &Notepad::imprimer);
    connect(ui->NOtepad_afficher, &QPushButton::clicked, this,  &Notepad::affiche);
    connect(ui->pushButton_enregister_sous, &QPushButton::clicked, this,  &Notepad::enregistrer_sous);
    connect(ui->Notepad_Undo, &QPushButton::clicked, this,  &Notepad::Undo);
    connect(ui->pushButton_Ecrire, &QPushButton::clicked, this,  &Notepad::ecrire);


}
void Notepad::enregistrer_sous()
{
    // Opens a dialog for saving a file
       QString fileName = QFileDialog::getSaveFileName(this, "Save as");

       // An object for reading and writing files
       QFile file(fileName);

       // Try to open a file with write only options
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
           return;
       }

       // Store the currentFile name
       currentFile = fileName;

       // Set the title for the window to the file name
       setWindowTitle(fileName);

       // Interface for writing text
       QTextStream out(&file);

       // Copy text in the textEdit widget and convert to plain text
       QString text = ui->textEdit->toPlainText();

       // Output to file
       out << text;

       // Close the file
       file.close();
}
void Notepad::ouvrir()
{
    // Opens a dialog that allows you to select a file to open
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    // An object for reading and writing files
    QFile file(fileName);

    // Store the currentFile name
    currentFile = fileName;

    // Try to open the file as a read only file if possible or display a
    // warning dialog box
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    // Set the title for the window to the file name
    setWindowTitle(fileName);

    // Interface for reading text
    QTextStream in(&file);

    // Copy text in the string
    QString text = in.readAll();

    // Put the text in the textEdit widget
    ui->textEdit->setText(text);

    // Close the file
    file.close();
}
void Notepad::Quitter()
{
  ui->groupBox_Notepad->hide();
  ui->gestion_inspection->show();
}
void Notepad::Undo()
{
     ui->textEdit->undo();
}
void Notepad::affiche()
{
    ui->textEdit->hide();

        QString filePath = "C:/Users/Beats SQA/Desktop/notepad.txt";

        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            QString fileContent = stream.readAll();
            file.close();

            if (fileContent.isEmpty()) {
                QMessageBox::information(this, "Empty", "The file is empty.");
            } else {
                ui->textBrowser->setText(fileContent);
            }
        } else {
            QMessageBox::warning(this, "Error", "Failed to open the file.");
        }
          ui->textBrowser->show();
}
void Notepad::imprimer()
{
    // Allows for interacting with printer
    QPrinter printer;

    // You'll put your printer name here
    printer.setPrinterName("Printer Name");

    // Create the print dialog and pass the name and parent
    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }

    // Send the text to the printer
    ui->textEdit->print(&printer);

}

void Notepad::enregistrer()
{
    QString msg=ui->textEdit->toPlainText();
    QFile file("C:/Users/Beats SQA/Desktop/notepad.txt");
                    if (file.open(QIODevice::Append | QIODevice::Text)) {
                        QTextStream stream(&file);
                        stream << " " << msg << ", \n Time: " << QDateTime::currentDateTime().toString() << endl;
                        file.close();
                    }
      ui->textEdit->clear();
}

void Notepad::ecrire()
{
  ui->textEdit->show();
}
