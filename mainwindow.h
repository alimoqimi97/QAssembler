#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "assembler.h"
#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Assembler assembler;

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
