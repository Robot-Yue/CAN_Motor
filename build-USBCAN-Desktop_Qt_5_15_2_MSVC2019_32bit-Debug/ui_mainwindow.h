/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_23;
    QLineEdit *lineEdit_pulse_Now;
    QLabel *label_25;
    QPushButton *pushButton_PositionAsk;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_24;
    QLineEdit *lineEdit_pulse_Now_M;
    QPushButton *pushButton_PositionAskM;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_22;
    QLineEdit *lineEdit_pulseTarget;
    QPushButton *pushButton_pulseStart;
    QPushButton *pushButton_SetZero;
    QPushButton *pushButton_gotoLimitSwitch;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_17;
    QLineEdit *lineEdit_canID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_DIR;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLineEdit *lineEdit_speedRPM;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEdit_AccSpeed;
    QPushButton *pushButton_speedStop;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_speeddown;
    QLabel *label_20;
    QLineEdit *lineEdit_DecSpeed;
    QPushButton *pushButton_speedUp;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_canChannel;
    QLabel *label_canHardVersion;
    QLabel *label_canSoftVersion;
    QLabel *label_InterruptNum;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_6;
    QComboBox *comboBox_5;
    QComboBox *comboBox_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QPushButton *pushButtonOpenCan;
    QPushButton *pushButton_resetCan;
    QPushButton *pushButton_InitCan;
    QPushButton *pushButton_startCan;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(731, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font;
        font.setPointSize(12);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(248, 219, 255);\n"
"border:2px solid blue;\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_6->addWidget(label_23);

        lineEdit_pulse_Now = new QLineEdit(groupBox_2);
        lineEdit_pulse_Now->setObjectName(QString::fromUtf8("lineEdit_pulse_Now"));

        horizontalLayout_6->addWidget(lineEdit_pulse_Now);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_6->addWidget(label_25);

        pushButton_PositionAsk = new QPushButton(groupBox_2);
        pushButton_PositionAsk->setObjectName(QString::fromUtf8("pushButton_PositionAsk"));

        horizontalLayout_6->addWidget(pushButton_PositionAsk);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_7->addWidget(label_24);

        lineEdit_pulse_Now_M = new QLineEdit(groupBox_2);
        lineEdit_pulse_Now_M->setObjectName(QString::fromUtf8("lineEdit_pulse_Now_M"));

        horizontalLayout_7->addWidget(lineEdit_pulse_Now_M);

        pushButton_PositionAskM = new QPushButton(groupBox_2);
        pushButton_PositionAskM->setObjectName(QString::fromUtf8("pushButton_PositionAskM"));

        horizontalLayout_7->addWidget(pushButton_PositionAskM);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_8->addWidget(label_22);

        lineEdit_pulseTarget = new QLineEdit(groupBox_2);
        lineEdit_pulseTarget->setObjectName(QString::fromUtf8("lineEdit_pulseTarget"));

        horizontalLayout_8->addWidget(lineEdit_pulseTarget);

        pushButton_pulseStart = new QPushButton(groupBox_2);
        pushButton_pulseStart->setObjectName(QString::fromUtf8("pushButton_pulseStart"));

        horizontalLayout_8->addWidget(pushButton_pulseStart);


        verticalLayout->addLayout(horizontalLayout_8);

        pushButton_SetZero = new QPushButton(groupBox_2);
        pushButton_SetZero->setObjectName(QString::fromUtf8("pushButton_SetZero"));

        verticalLayout->addWidget(pushButton_SetZero);

        pushButton_gotoLimitSwitch = new QPushButton(groupBox_2);
        pushButton_gotoLimitSwitch->setObjectName(QString::fromUtf8("pushButton_gotoLimitSwitch"));

        verticalLayout->addWidget(pushButton_gotoLimitSwitch);


        gridLayout_3->addWidget(groupBox_2, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(248, 219, 255);\n"
"border:2px solid blue;\n"
"}"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout->addWidget(label_17);

        lineEdit_canID = new QLineEdit(groupBox_3);
        lineEdit_canID->setObjectName(QString::fromUtf8("lineEdit_canID"));

        horizontalLayout->addWidget(lineEdit_canID);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_DIR = new QLineEdit(groupBox_3);
        lineEdit_DIR->setObjectName(QString::fromUtf8("lineEdit_DIR"));

        horizontalLayout_3->addWidget(lineEdit_DIR);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_4->addWidget(label_15);

        lineEdit_speedRPM = new QLineEdit(groupBox_3);
        lineEdit_speedRPM->setObjectName(QString::fromUtf8("lineEdit_speedRPM"));

        horizontalLayout_4->addWidget(lineEdit_speedRPM);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEdit_AccSpeed = new QLineEdit(groupBox_3);
        lineEdit_AccSpeed->setObjectName(QString::fromUtf8("lineEdit_AccSpeed"));

        horizontalLayout_5->addWidget(lineEdit_AccSpeed);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        pushButton_speedStop = new QPushButton(groupBox_3);
        pushButton_speedStop->setObjectName(QString::fromUtf8("pushButton_speedStop"));

        gridLayout_2->addWidget(pushButton_speedStop, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_speeddown = new QPushButton(groupBox_3);
        pushButton_speeddown->setObjectName(QString::fromUtf8("pushButton_speeddown"));

        horizontalLayout_2->addWidget(pushButton_speeddown);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_2->addWidget(label_20);

        lineEdit_DecSpeed = new QLineEdit(groupBox_3);
        lineEdit_DecSpeed->setObjectName(QString::fromUtf8("lineEdit_DecSpeed"));

        horizontalLayout_2->addWidget(lineEdit_DecSpeed);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        pushButton_speedUp = new QPushButton(groupBox_3);
        pushButton_speedUp->setObjectName(QString::fromUtf8("pushButton_speedUp"));

        gridLayout_2->addWidget(pushButton_speedUp, 2, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(248, 219, 255);\n"
"border:2px solid blue;\n"
"}"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_8);


        gridLayout_5->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_canChannel = new QLabel(groupBox_4);
        label_canChannel->setObjectName(QString::fromUtf8("label_canChannel"));

        verticalLayout_4->addWidget(label_canChannel);

        label_canHardVersion = new QLabel(groupBox_4);
        label_canHardVersion->setObjectName(QString::fromUtf8("label_canHardVersion"));

        verticalLayout_4->addWidget(label_canHardVersion);

        label_canSoftVersion = new QLabel(groupBox_4);
        label_canSoftVersion->setObjectName(QString::fromUtf8("label_canSoftVersion"));

        verticalLayout_4->addWidget(label_canSoftVersion);

        label_InterruptNum = new QLabel(groupBox_4);
        label_InterruptNum->setObjectName(QString::fromUtf8("label_InterruptNum"));

        verticalLayout_4->addWidget(label_InterruptNum);


        gridLayout_5->addLayout(verticalLayout_4, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(248, 219, 255);\n"
"border:2px solid blue;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox_6 = new QComboBox(groupBox_5);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setEnabled(true);

        verticalLayout_2->addWidget(comboBox_6);

        comboBox_5 = new QComboBox(groupBox_5);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setEnabled(true);

        verticalLayout_2->addWidget(comboBox_5);

        comboBox_4 = new QComboBox(groupBox_5);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        verticalLayout_2->addWidget(comboBox_4);


        gridLayout_3->addWidget(groupBox_5, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(248, 219, 255);\n"
"border:2px solid blue;\n"
"}"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 2, 1, 1, 1);

        pushButtonOpenCan = new QPushButton(groupBox);
        pushButtonOpenCan->setObjectName(QString::fromUtf8("pushButtonOpenCan"));

        gridLayout->addWidget(pushButtonOpenCan, 3, 0, 1, 1);

        pushButton_resetCan = new QPushButton(groupBox);
        pushButton_resetCan->setObjectName(QString::fromUtf8("pushButton_resetCan"));
        pushButton_resetCan->setEnabled(false);

        gridLayout->addWidget(pushButton_resetCan, 3, 1, 1, 1);

        pushButton_InitCan = new QPushButton(groupBox);
        pushButton_InitCan->setObjectName(QString::fromUtf8("pushButton_InitCan"));
        pushButton_InitCan->setEnabled(false);

        gridLayout->addWidget(pushButton_InitCan, 4, 0, 1, 1);

        pushButton_startCan = new QPushButton(groupBox);
        pushButton_startCan->setObjectName(QString::fromUtf8("pushButton_startCan"));
        pushButton_startCan->setEnabled(false);

        gridLayout->addWidget(pushButton_startCan, 4, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\346\216\247\345\210\266", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\234\210", nullptr));
        pushButton_PositionAsk->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256\345\234\210\346\225\260\346\237\245\350\257\242", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\347\274\226\347\240\201\345\231\250\345\217\215\351\246\210\345\200\274", nullptr));
        pushButton_PositionAskM->setText(QCoreApplication::translate("MainWindow", "\347\274\226\347\240\201\345\231\250\345\217\215\351\246\210\345\200\274\346\237\245\350\257\242", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\256\232\344\275\215\350\204\211\345\206\262\346\225\260", nullptr));
        pushButton_pulseStart->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\346\250\241\345\274\217\345\220\257\345\212\250", nullptr));
        pushButton_SetZero->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\216\245\345\260\206\345\275\223\345\211\215\344\275\215\347\275\256\350\256\276\347\275\256\344\270\272\351\233\266\347\202\271", nullptr));
        pushButton_gotoLimitSwitch->setText(QCoreApplication::translate("MainWindow", "\351\231\220\344\275\215\345\275\222\351\233\266\357\274\210\350\277\220\345\212\250\345\210\260\351\231\220\344\275\215\345\274\200\345\205\263\344\275\215\347\275\256\345\201\234\344\270\213\346\235\245\357\274\211", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\346\216\247\345\210\266", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\234\272ID\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\226\271\345\220\221(0\351\241\272\346\227\266\351\222\210)", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\350\275\254\351\200\237", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246", nullptr));
        pushButton_speedStop->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\347\253\213\345\215\263\345\201\234\346\255\242(\344\275\216\351\200\237\346\250\241\345\274\217\344\275\277\347\224\250)", nullptr));
        pushButton_speeddown->setText(QCoreApplication::translate("MainWindow", "\345\207\217\351\200\237\345\201\234\346\255\242", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\345\207\217\351\200\237\345\272\246", nullptr));
        pushButton_speedUp->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\346\250\241\345\274\217\345\220\257\345\212\250", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\243\346\235\277\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CAN\351\200\232\351\201\223\346\225\260\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\241\254\344\273\266\347\211\210\346\234\254\345\217\267:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\243\345\272\223\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\344\270\255\346\226\255\345\217\267:", nullptr));
        label_canChannel->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_canHardVersion->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_canSoftVersion->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        label_InterruptNum->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\346\240\274\345\274\217\350\256\276\347\275\256", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\345\270\247", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("MainWindow", "\346\211\251\345\261\225\345\270\247", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\270\247", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "\350\277\234\347\250\213\345\270\247", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "USB-CAN\346\250\241\345\235\227\351\200\232\351\201\2230", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "USB-CAN\346\250\241\345\235\227\351\200\232\351\201\2231", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "USBCAN-2A", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "USBCAN-2C", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "CANalyst-II", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\264\242\345\274\225\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_2->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_2->setItemText(11, QCoreApplication::translate("MainWindow", "11", nullptr));
        comboBox_2->setItemText(12, QCoreApplication::translate("MainWindow", "12", nullptr));
        comboBox_2->setItemText(13, QCoreApplication::translate("MainWindow", "13", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "500Kbps", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "20Kbps", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "40Kbps", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "50Kbps", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "80Kbps", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("MainWindow", "100Kbps", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("MainWindow", "125Kbps", nullptr));
        comboBox_3->setItemText(7, QCoreApplication::translate("MainWindow", "200Kbps", nullptr));
        comboBox_3->setItemText(8, QCoreApplication::translate("MainWindow", "250Kbps", nullptr));
        comboBox_3->setItemText(9, QCoreApplication::translate("MainWindow", "400Kbps", nullptr));
        comboBox_3->setItemText(10, QCoreApplication::translate("MainWindow", "10Kbps", nullptr));
        comboBox_3->setItemText(11, QCoreApplication::translate("MainWindow", "666Kbps", nullptr));
        comboBox_3->setItemText(12, QCoreApplication::translate("MainWindow", "800Kbps", nullptr));
        comboBox_3->setItemText(13, QCoreApplication::translate("MainWindow", "1000Kbps", nullptr));

        pushButtonOpenCan->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        pushButton_resetCan->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        pushButton_InitCan->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226CAN", nullptr));
        pushButton_startCan->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250CAN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
