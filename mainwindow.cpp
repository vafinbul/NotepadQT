#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString file_name = QFileDialog::getOpenFileName(this) ;
   QFile file(file_name) ;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->plainTextEdit->document()->setPlainText(text);

    }

}

