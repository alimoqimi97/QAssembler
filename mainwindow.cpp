#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
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


    QList<QVector<int>> mcl = assembler.getMcl();

    ui->tableWidget->setRowCount(mcl.size());
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setColumnWidth(0,400);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Machinecode"));

    for(int i = 0 ; i < mcl.size() ; i++)
    {
        QVector<int> mc = mcl.at(i);
        QString temp;

        for(int j = 0 ; j < mc.size() ; j++)
        {
            temp.push_back(QString::number(mc.at(j)));
        }
        ui->tableWidget->setItem((i + 1),0,new QTableWidgetItem(temp));
    }


    ui->tableWidget_2->setRowCount(assembler.getMcl().size());
    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setColumnWidth(0,400);
    ui->tableWidget_2->setHorizontalHeaderItem(0,new QTableWidgetItem("Assemblycode"));

    QFile f(filepath);
    QTextStream see(&f);
    QString asline = "a";
    int lineindex = 1;

    f.open(QIODevice::ReadOnly);

    while(!asline.isEmpty())
    {
        asline = see.readLine();

        ui->tableWidget_2->setItem(lineindex,0,new QTableWidgetItem(asline));
        ++lineindex;
    }
    f.close();

}
