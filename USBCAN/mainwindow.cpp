#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    labelMessage = new QLabel();  // 创建这个 label 实例，将来嵌入状态栏要用

    this->setWindowTitle(u8"CAN电机调试上位机");

    canthread = new CANThread();
    connect(canthread, &CANThread::getProtocolData, this, &MainWindow::onGetProtocolData);
    connect(canthread, &CANThread::boardInfo, this, &MainWindow::onBoardInfo);
    connect(this, &MainWindow::getValidDatalist, this, &MainWindow::onGetValidDatalist);
}

MainWindow::~MainWindow() {
    delete ui;
}

// 打开 USB-CAN 模块
void MainWindow::on_pushButtonOpenCan_clicked() {
    if (ui->pushButtonOpenCan->text() == tr(u8"打开设备")) {
        UINT baundRate = 0;
        if (ui->comboBox_3->currentText().indexOf("Kbps") != -1)
            baundRate = ui->comboBox_3->currentText().remove("Kbps").toUInt();
        else
            baundRate = QVariant(ui->comboBox_3->currentText().remove("Mbps").toFloat()).toUInt();
        bool dev = canthread->openDevice(4,                                                 // 这是USB-CAN 模块的设备类型，根据厂家给的说明，这个类型对应数值为 4
                                         QVariant(ui->comboBox_2->currentIndex()).toUInt(), // 这里只有1个设备，这个值索引值会是 0，
                                         baundRate);
        //  openDevice 函数有返回值，如果为 1，则打开成功
        if (dev == true) {
            ui->comboBox->setEnabled(false);
            ui->comboBox_2->setEnabled(false);
            ui->comboBox_3->setEnabled(false);
            ui->pushButton_InitCan->setEnabled(true);
            ui->pushButtonOpenCan->setText(tr(u8"关闭设备"));
            labelMessage->setText(u8"USB-CAN模块连接成功");
            ui->statusBar->addWidget(labelMessage);
        } else
            QMessageBox::warning(this, u8"警告", u8"打开设备失败！");
    } else if (ui->pushButtonOpenCan->text() == tr(u8"关闭设备")) {
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);

        ui->pushButton_InitCan->setEnabled(false);
        ui->pushButton_startCan->setEnabled(false);
        ui->pushButton_resetCan->setEnabled(false);
        ui->pushButtonOpenCan->setText(tr(u8"打开设备"));
        canthread->stop();
        canthread->closeDevice();
    }
}

// 这是自子线程中  emit（GetProtocolDate）的槽函数，通过传参的方法，把子线程收到的 电机发回数据， 在主线程中得到，可以在这里做数据处理
void MainWindow::onGetProtocolData(VCI_CAN_OBJ *vci, unsigned int dwRel, unsigned int channel) {
    QStringList messageList;
    QString str;
    for (unsigned int i = 0; i < dwRel; i++) {
        messageList.clear();
        messageList << QTime::currentTime().toString("hh:mm:ss zzz"); // 时间
        if (vci[i].TimeFlag == 1) {
            messageList << "0x" + QString("%1").arg(vci[i].TimeStamp, 8, 16, QChar('0')).toUpper();         // 时间
            messageList << QString("%1").arg(QVariant(vci[i].TimeStamp * 0.1).toUInt(), 8, 10, QChar('0')); // 时间
        } else {
            messageList << "无"; // 时间
            messageList << "无"; // 时间
        }
        messageList << "CH" + QString::number(channel);
        messageList << u8"接收";                                                         // 收发
        messageList << "0x" + QString("%1").arg(vci[i].ID, 8, 16, QChar('0')).toUpper(); // ID
        messageList << ((vci[i].RemoteFlag == 1) ? u8"远程帧" : u8"数据帧");             // 类型
        messageList << ((vci[i].ExternFlag == 1) ? u8"扩展帧" : u8"标准帧");             // Frame
        QString str = "";
        // 数据帧显示数据
        if (vci[i].RemoteFlag == 0) {
            messageList << "0x" + QString::number(vci[i].DataLen, 16).toUpper(); // 长度
            str = "x| ";
            for (int j = 0; j < vci[i].DataLen; j++) {
                str += QString("%1 ").arg(vci[i].Data[j], 2, 16, QChar('0')).toUpper(); // QString::number(recvCANData[i].frame.data[j],16) + " ";
                validData[j] = vci[i].Data[j];                                          //  这个数组中就存有8个 每2位数组成的 数字， 每2位数组成十进制的数值
                                                                                        //     qDebug()<<"有效数据data[]是："<<validData[j];
            }
        } else {
            messageList << "0x0"; // 长度
        }
        messageList << str;       // 数据
        qDebug() << messageList;

        // if(validData[0]==0x30)
        emit getValidDatalist();
    }
}

QString versionStr(USHORT ver) {
    return "V" + QString::number((ver & 0x0FFF) / 0x100, 16).toUpper() + "." + QString("%1 ").arg((ver & 0x0FFF) % 0x100, 2, 16, QChar('0')).toUpper();
}

void MainWindow::onBoardInfo(VCI_BOARD_INFO vbi) {
    ui->label_canChannel->setText(QString::number(vbi.can_Num));
    ui->label_canHardVersion->setText(versionStr(vbi.hw_Version));
    ui->label_canSoftVersion->setText(versionStr(vbi.in_Version));
    ui->label_InterruptNum->setText(QString::number(vbi.irq_Num));
}

// 给 USB-CAN 模块初始化
void MainWindow::on_pushButton_InitCan_clicked() {
    if (canthread->initCAN()) {
        ui->pushButton_startCan->setEnabled(true);
        ui->pushButton_InitCan->setEnabled(false);
        labelMessage->setText(u8"USB-CAN模块 初始化成功");
        ui->statusBar->addWidget(labelMessage);
    } else {
        QMessageBox::warning(this, u8"警告", u8"CAN初始化失败！");
    }
}

// 启动 USB-CAN 模块
void MainWindow::on_pushButton_startCan_clicked() {
    if (canthread->startCAN()) {
        ui->pushButton_startCan->setEnabled(false);
        ui->pushButton_resetCan->setEnabled(true);

        labelMessage->setText(u8"USB-CAN模块 启动成功");
        ui->statusBar->addWidget(labelMessage);
        canthread->start();  // 这里开启子线程，在子线程里面接收电机发回的数据帧
    } else {
        QMessageBox::warning(this, u8"警告", u8"CAN启动失败！");
    }
}

// 速度控制模式
// 这个函数里只组织好要发送的  字符list， 然后调用 CanDataSendout(QStringList list);发出去
void MainWindow::on_pushButton_speedUp_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        //  得到要发送对象的canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString accStr = QString::number((ui->lineEdit_AccSpeed->text().toInt()), 16);

    int speed = ui->lineEdit_speedRPM->text().toInt(); // 16进制表示的转速

    int dir = ui->lineEdit_DIR->text().toInt(); // 16进制表示的方向

    int secondNum;

    qDebug() << u8"速度控制中，速度值换算为16进制，字符串打印出来是" << QString::number(speed, 16);

    // 代表 CCW 逆时针转动
    if (dir == 0) {
        secondNum = (speed >> 8) & 0x0f; // 确保第二个字节起始位是0
        qDebug() << u8"dir=0，取出速度值的最高8位是" << secondNum;
    }
    // 代表 CW 顺时针转动
    if (dir == 1) {
        secondNum = (speed >> 8) | 0x80;  // 确保第二个字节起始位是1
        qDebug() << u8"dir=1时，取出速度值的最高8位是" << secondNum;
    }

    QString secondByteStr, thirdByteStr, CRC_str;
    secondByteStr = QString::number(secondNum, 16); // 得到应填入的第二个字节的字符串
    int thirdNum = speed & 0xff;
    thirdByteStr = QString::number(thirdNum, 16); //  得到应填入第三个字节的字符串

    qDebug() << u8"速度控制中，从输入框取到的值,应填入第3字节的字符串是" << thirdByteStr;
    //--------------------------

    QString controlCode = "F6";

    int crcNumber = ui->lineEdit_canID->text().toInt() + secondByteStr.toInt(Q_NULLPTR, 16) + thirdByteStr.toInt(Q_NULLPTR, 16) + controlCode.toInt(Q_NULLPTR, 16) + ui->lineEdit_AccSpeed->text().toInt();

    //  qDebug()<<ui->lineEdit_canID->text().toInt();
    //  qDebug()<<secondByteStr.toInt(Q_NULLPTR,16);
    //   qDebug()<<thirdByteStr.toInt(Q_NULLPTR,16);
    //   qDebug()<<controlCode.toInt(Q_NULLPTR,16);

    //  qDebug()<<"CRC="<<(crcNumber&0xff);

    CRC_str = QString::number((crcNumber & 0xff), 16);

    //  qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + secondByteStr + " " + thirdByteStr + " " + accStr + " " + CRC_str;
    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);
}

// 以减速模式停止
// 只组织好字符 list，最后调用 CanDataSendout(commandList) 函数
void MainWindow::on_pushButton_speeddown_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0)  {
        // 得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16); //  把输入框里的数值转换为16进制后，再转换为字符串形式

    QString DecSpeed = QString::number((ui->lineEdit_DecSpeed->text().toInt()), 16); //  把输入框里的数值转换为16进制后，再转换为字符串形式

    QString controlCode = "F6";

    int crcNumber = ui->lineEdit_canID->text().toInt() + controlCode.toInt(Q_NULLPTR, 16) + 0 + 0 + ui->lineEdit_DecSpeed->text().toInt();

    // 停止指令是 ID号 F6 00  00 Dec CRC
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + "0" + " " + "0" + " " + DecSpeed + " " + CRC_str; // //  停止指令字符串（不包括电机ID号）是 F6 00 00 00

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);
}

// 立即停止，只适用于低速模式
void MainWindow::on_pushButton_speedStop_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        //  得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString controlCode = "F6";

    int crcNumber = ui->lineEdit_canID->text().toInt() + 0 + 0 + controlCode.toInt(Q_NULLPTR, 16) + 0;  // 停止指令是 01 F6 00 00 00
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + "0" + " " + "0" + " " + "0" + " " + CRC_str;  // 停止指令字符串（不包括电机ID号）是 F6 00 00 00

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);
}
// 把其他按钮槽函数组织好的字符 list 通过调用 canthread 线程总的 sendDate 函数发出去
void MainWindow::CanDataSendout(QStringList list) {
    // 把其他指令组织好的字符串 list 传入，进行发送操作
    strList = list; 

    unsigned char data[8];
    memset(data, 0, 8);
    UINT dlc = 0;
    dlc = strList.count() > 8 ? 8 : strList.count();
    for (int i = 0; i < dlc; i++)
        data[i] = strList.at(i).toInt(Q_NULLPTR, 16);
    if (canthread->sendData(QVariant(ui->comboBox_4->currentIndex()).toUInt(),                  // 这是指当前使用 USB-CAN 模块的那个通道号，如用通道 1，此值为 0
                            QVariant(ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16)).toUInt(), // 这是发送对象的 canID 号（电机的 canID 号）
                            ui->comboBox_5->currentIndex(),                                     // 判断是 标准帧 还是 扩展帧
                            ui->comboBox_6->currentIndex(),                                     // 判断是 数据帧 还是 远程帧
                            data, dlc))                                                         // 要发送的数据 和 数据长度
    {                                                                                           // 发送成功，打印数据

        QString labelMessageStr;

        for (int i = 0; i < strList.length(); i++) {
            labelMessageStr.append(strList.at(i));
            labelMessageStr.append(" ");
        }

        labelMessage->setText(labelMessageStr);  // 把发送出去的 16 进制字符串，显示在状态栏上

        ui->statusBar->addWidget(labelMessage);
    }
    else
        QMessageBox::warning(this, u8"警告", u8"数据发送失败！");
}

// 位置控制模式
void MainWindow::on_pushButton_pulseStart_clicked() {
    qDebug() << u8"打印=" << ui->lineEdit_pulseTarget->text().toInt();

    int pulseNum = ui->lineEdit_pulseTarget->text().toInt();

    int highNum = pulseNum & 0xff0000;
    qDebug() << u8"打印high=" << highNum;

    int highshort = highNum >> 16;
    qDebug() << u8"打印highshort=" << highshort;

    int midNum = pulseNum & 0x00ff00;
    qDebug() << u8"打印mid=" << midNum;

    int midshort = midNum >> 8;
    qDebug() << u8"打印midshort=" << midshort;

    int endNum = pulseNum & 0x0000ff;
    qDebug() << u8"打印end=" << endNum;

    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        // 得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    qDebug() << "addressID=" << addressID;

    QString accStr = QString::number((ui->lineEdit_AccSpeed->text().toInt()), 16);

    qDebug() << "accStr=" << accStr;

    int speed = ui->lineEdit_speedRPM->text().toInt();  // 16 进制表示的转速

    int dir = ui->lineEdit_DIR->text().toInt();  // 16 进制表示的方向
    QString secondByteStr, thirdByteStr, pulseStr1, pulseStr2, pulseStr3, CRC_str;

    pulseStr1 = QString::number(highshort, 16);
    pulseStr2 = QString::number(midshort, 16);
    pulseStr3 = QString::number(endNum, 16);

    qDebug() << "pulseStr1=" << pulseStr1;

    //---------------------------
    int secondNum;

    qDebug() << u8"速度控制中，速度值换算为16进制，字符串打印出来是" << QString::number(speed, 16);

    // 代表 CCW 逆时针转动
    if (dir == 0) {
        secondNum = (speed >> 8) & 0x0f;  // 确保第二个字节起始位是 0
        qDebug() << u8"dir=0，取出速度值的最高8位是" << secondNum;
    }
    //  代表 CW 顺时针转动
    if (dir == 1) {
        secondNum = (speed >> 8) | 0x80;  // 确保第二个字节起始位是 1
        qDebug() << u8"dir=1时，取出速度值的最高8位是" << secondNum;
    }
    secondByteStr = QString::number(secondNum, 16); // 得到应填入的第二个字节的字符串
    int thirdNum = speed & 0xff;
    thirdByteStr = QString::number(thirdNum, 16);   // 得到应填入第三个字节的字符串

    qDebug() << u8"速度控制中，从输入框取到的值,应填入第3字节的字符串是" << thirdByteStr;
    //--------------------------

    QString controlCode = "FD";

    int crcNumber = ui->lineEdit_canID->text().toInt() + secondByteStr.toInt(Q_NULLPTR, 16) + thirdByteStr.toInt(Q_NULLPTR, 16) + controlCode.toInt(Q_NULLPTR, 16) + ui->lineEdit_AccSpeed->text().toInt() + highshort + midshort + endNum;

    CRC_str = QString::number((crcNumber & 0xff), 16);

    QString strListOriginal = controlCode + " " + secondByteStr + " " + thirdByteStr + " " + accStr + " " + pulseStr1 + " " + pulseStr2 + " " + pulseStr3 + " " + CRC_str;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);
}

// 查询进位制多圈编码器值
void MainWindow::on_pushButton_PositionAsk_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        // 得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString controlCode = "30";

    int crcNumber = ui->lineEdit_canID->text().toInt() + controlCode.toInt(Q_NULLPTR, 16); //  停止指令是 30 CRC
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //  qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + CRC_str;  // 停止指令字符串（不包括电机ID号）是 30 CRC

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);

    command = "30";
}

// 槽函数，把当前编码器的值，换算成圈数，在位置显示框里显示出来
void MainWindow::onGetValidDatalist() {
    if (validData[0] == 0x30) {
        qDebug() << u8"读取进位制多圈编码器值，当前命令是： " << command;

        int encodeNum = validData[5] * 256 + validData[6];                        //  这是编码器值
        int circleNum = validData[2] * 65536 + validData[3] * 256 + validData[4]; //  这是编码器的进位值  就是说，电机转过了多少圈

        qDebug() << u8"编码器当前值是：" << encodeNum;
        qDebug() << u8"编码器进位值是：" << circleNum;
        float circle = circleNum + (encodeNum / 16384.0);  // 16384 是 0X4000对应的 16进制数， 电机说明书上说，  编码器0x4000 对应电机转过360度。

        ui->lineEdit_pulse_Now->setText(QString::number(circle, 'f', 2));
    }

    if (validData[0] == 0x31) {
        qDebug() << u8"读取累加制多圈编码器值，当前命令是31： " << command;

        QString encodeFeedbackStr;

        encodeFeedbackStr.clear();
        encodeFeedbackStr.append("0X ");

        //  说明书上说：编码器反馈值的 8 个字节中，从底 2--7 个字节是 编码器反馈值
        for (int n = 1; n <= 6; n++) {
            encodeFeedbackStr.append(QString::number(validData[n], 16));
            encodeFeedbackStr.append(" ");
        }

        qDebug() << "encodefeedback  is  " << encodeFeedbackStr;

        ui->lineEdit_pulse_Now_M->setText(encodeFeedbackStr);
    }
}

// 读取累加制多圈编码器 命令 31
void MainWindow::on_pushButton_PositionAskM_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        // 得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString controlCode = "31";

    int crcNumber = ui->lineEdit_canID->text().toInt() + controlCode.toInt(Q_NULLPTR, 16); //  停止指令是 30 CRC
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + CRC_str;  // 停止指令字符串（不包括电机ID号）是 30 CRC

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);

    command = "31";
}

// 将当前位置设为零点
void MainWindow::on_pushButton_SetZero_clicked() {
    // 标准帧，ID 范围 0-0x7FF
    if (ui->comboBox_6->currentIndex() == 0) {
        // 得到要发送对象的 canID
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x7FF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    } else {
        if (ui->lineEdit_canID->text().toInt(Q_NULLPTR, 16) > 0x1FFFFFFF) {
            QMessageBox::warning(this, u8"警告", u8"发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }

    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString controlCode = "92";

    int crcNumber = ui->lineEdit_canID->text().toInt() + controlCode.toInt(Q_NULLPTR, 16); //  停止指令是 30 CRC
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + CRC_str; // //  停止指令字符串（不包括电机ID号）是 30 CRC

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);

    command = "92";
}

// 限位归零，运动到当前限位开关所在位置停下来
void MainWindow::on_pushButton_gotoLimitSwitch_clicked() {
    QString addressID = QString::number((ui->lineEdit_canID->text().toInt()), 16);

    QString controlCode = "91";

    int crcNumber = ui->lineEdit_canID->text().toInt() + controlCode.toInt(Q_NULLPTR, 16); //  停止指令是 30 CRC
    QString CRC_str = QString::number((crcNumber & 0xff), 16);

    //qDebug()<<"CRCSTR="<<CRC_str;

    QString strListOriginal = controlCode + " " + CRC_str;  // 停止指令字符串（不包括电机ID号）是 30 CRC

    qDebug() << "strListOriginal=" << strListOriginal;

    QStringList commandList = strListOriginal.split(" ");

    CanDataSendout(commandList);

    command = "91";
}
