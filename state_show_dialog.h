#ifndef STATE_SHOW_DIALOG_H
#define STATE_SHOW_DIALOG_H

#include <QDialog>

namespace Ui {
class State_Show_Dialog;
}

class State_Show_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit State_Show_Dialog(QWidget *parent = 0);
    void dialog_init();
    ~State_Show_Dialog();

private slots:
    void on_closeBtn_clicked();
    void updateState();
private:
    Ui::State_Show_Dialog *ui;
    QTimer *timer;
    int AXIS;                   //轴
    short sRtn;                 // 指令返回值变量
    long AxisStatus;          // 轴状态
};

#endif // STATE_SHOW_DIALOG_H
