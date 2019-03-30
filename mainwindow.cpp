#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_pressed()
{
    this->close();
}

void MainWindow::on_pushButton_2_pressed()
{
    QString fileaddress = QFileDialog::getOpenFileName(
                this,
                tr("select file"),
                "D://",
                tr("ASM files (*.ASM)")
                );

    ui->lineEdit->setText(fileaddress);
//    assembler.OperateOnAssemblyFile(fileaddress);

}

void MainWindow::on_pushButton_3_pressed()
{
    QString filepath = ui->lineEdit->text();

    if(filepath.isEmpty())
    {
        return;
    }

    assembler.OperateOnAssemblyFile(filepath);
}
