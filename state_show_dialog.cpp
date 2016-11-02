#include "state_show_dialog.h"
#include "ui_state_show_dialog.h"
#include<QTimer>
#include<gts.h>
#include"command.h"
State_Show_Dialog::State_Show_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::State_Show_Dialog)
{
    ui->setupUi(this);
    dialog_init();
}

void State_Show_Dialog::dialog_init()
{
    setWindowTitle("状态检测");
    ui->led_1->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_2->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_3->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_4->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_5->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_6->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_7->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_8->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_9->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_10->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_11->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    ui->led_12->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    updateState();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateState()));
    timer->start(500);
}

State_Show_Dialog::~State_Show_Dialog()
{

    delete ui;
}

void State_Show_Dialog::on_closeBtn_clicked()
{
    timer->stop();
    timer->deleteLater();
    close();
}

void State_Show_Dialog::updateState()   //更新状态灯
{

    AXIS=1;//一轴 == X轴
    sRtn = GT_GetSts(AXIS,&AxisStatus);
    //    commandhandler("GT_GetSts",sRtn);
    //    qDebug()<<(AxisStatus & 0x2);
    //伺服报警
    if(AxisStatus & 0x2)
    {
        ui->led_1->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_1->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //驱动使能
    if(AxisStatus & 0x200)
    {
        ui->led_2->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }else {
        ui->led_2->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }
    //正限位
    if(AxisStatus & 0x20)
    {
        ui->led_3->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_3->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //负限位

    if(AxisStatus & 0x40)
    {
        ui->led_4->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_4->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //正常运动
    if(AxisStatus & 0x10)
    {
        ui->led_13->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_13->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }

    AXIS=2;//二轴 == Y轴
    sRtn = GT_GetSts(AXIS,&AxisStatus);
    //    commandhandler("GT_GetSts",sRtn);
    //伺服报警
    if(AxisStatus & 0x2)
    {
        ui->led_5->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_5->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //驱动使能

    if(AxisStatus & 0x200)
    {
        ui->led_6->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }else {
        ui->led_6->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }
    //正限位

    if(AxisStatus & 0x20)
    {
        ui->led_7->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_7->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //负限位

    if(AxisStatus & 0x40)
    {
        ui->led_8->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_8->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }

    //正常运动
    if(AxisStatus & 0x10)
    {
        ui->led_14->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_14->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }


    AXIS=3;//三轴 == 旋转轴
    sRtn = GT_GetSts(AXIS,&AxisStatus);
    //    commandhandler("GT_GetSts",sRtn);
    //伺服报警
    if(AxisStatus & 0x2)
    {
        ui->led_9->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_9->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //驱动使能

    if(AxisStatus & 0x200)
    {
        ui->led_10->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }else {
        ui->led_10->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }
    //正限位

    if(AxisStatus & 0x20)
    {
        ui->led_11->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_11->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }
    //负限位
    if(AxisStatus & 0x40)
    {
        ui->led_12->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_12->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }

    //正常运动
    if(AxisStatus & 0x10)
    {
        ui->led_15->setStyleSheet("QLabel{border-radius: 15px;background-color:red;}");
    }else {
        ui->led_15->setStyleSheet("QLabel{border-radius: 15px;background-color:green;}");
    }

}
