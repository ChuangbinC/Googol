#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"state_show_dialog.h"
#include"command.h"
#include<gts.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("宏动平台控制器");
    //打开控制器
    sRtn = GT_Open();
    commandhandler("GT_Open",sRtn);
    //系统复位
    sRtn = GT_Reset();
    commandhandler("GT_Reset",sRtn);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBtn_clicked()
{
    State_Show_Dialog *dialog = new State_Show_Dialog(this);
    dialog->show();
}
