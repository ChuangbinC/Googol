#ifndef COMMAND_H
#define COMMAND_H
#include<QDebug>
#include<QString>
// 该函数检测某条GT指令的执行结果， command为指令名称， error为指令执行返回值
/**
 * @brief commandhandler
 * @param command 输入命令名称
 * @param error 输入命令返回值
 */
static void commandhandler(QString command, short error)
{
    // 如果指令执行返回值为非0，说明指令执行错误， 向屏幕输出错误结果
    if(error)
    {
        qDebug()<<command<<"="<<error;
    }
}

#endif // COMMAND_H
