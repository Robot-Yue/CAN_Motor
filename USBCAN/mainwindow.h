#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canthread.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

    void getValidDatalist();

private slots:
    void onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel);
    void onBoardInfo(VCI_BOARD_INFO vbi);
    void on_pushButtonOpenCan_clicked();

    void on_pushButton_InitCan_clicked();

    void on_pushButton_startCan_clicked();

    void on_pushButton_speedUp_clicked();

    void on_pushButton_speeddown_clicked();

    void on_pushButton_speedStop_clicked();

    void on_pushButton_pulseStart_clicked();

    void on_pushButton_PositionAsk_clicked();

    void onGetValidDatalist();

    void on_pushButton_PositionAskM_clicked();

    void on_pushButton_SetZero_clicked();

    void on_pushButton_gotoLimitSwitch_clicked();

private:
    Ui::MainWindow *ui;
    CANThread *canthread;
    QLabel *labelMessage;

    QStringList strList;  // 定义这个来组织发送的命令字符串
    void CanDataSendout(QStringList list);

    QString command;
    uint validData[8];
};

#endif // MAINWINDOW_H
