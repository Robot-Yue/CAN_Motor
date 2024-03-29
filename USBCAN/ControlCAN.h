/* USB-CAN 模块厂商提供的函数包 */
#ifndef CONTROLCAN_H
#define CONTROLCAN_H

//#include <cvidef.h>	// 使用 CVI 平台开发，请使用该语句。

// 接口卡类型定义
#define VCI_USBCAN1  3
#define VCI_USBCAN2  4
#define VCI_USBCAN2A 4

#define VCI_USBCAN_E_U  20
#define VCI_USBCAN_2E_U 21

#define UINT   unsigned int
#define BYTE   unsigned char
#define USHORT unsigned short
#define UCHAR  unsigned char
#define UINT64 unsigned long long
#define CHAR   char
#define DWORD  unsigned int
#define ULONG  unsigned long
#define PVOID  void*
#define INT    int

// 函数调用返回状态值
#define	STATUS_OK  1
#define STATUS_ERR 0
	
/*------------------------------------------------兼容ZLG的函数及数据类型------------------------------------------------*/
// 1.ZLGCAN 系列接口卡信息的数据类型
typedef struct _VCI_BOARD_INFO {
    USHORT hw_Version;
    USHORT fw_Version;
    USHORT dr_Version;
    USHORT in_Version;
    USHORT irq_Num;
    BYTE   can_Num;
    CHAR   str_Serial_Num[20];
    CHAR   str_hw_Type[40];
    USHORT Reserved[4];
} VCI_BOARD_INFO, *PVCI_BOARD_INFO;

// 2.定义 CAN 信息帧的数据类型
typedef struct _VCI_CAN_OBJ {
    UINT ID;
    UINT TimeStamp;
    BYTE TimeFlag;
    BYTE SendType;
    BYTE RemoteFlag;  // 是否是远程帧
    BYTE ExternFlag;  // 是否是扩展帧
    BYTE DataLen;
    BYTE Data[8];
    BYTE Reserved[3];
}VCI_CAN_OBJ,*PVCI_CAN_OBJ;

// 3.定义初始化 CAN 的数据类型
typedef struct _VCI_INIT_CONFIG {
    DWORD AccCode;
    DWORD AccMask;
    DWORD Reserved;
    UCHAR Filter;
    UCHAR Timing0;
    UCHAR Timing1;
    UCHAR Mode;
}VCI_INIT_CONFIG, *PVCI_INIT_CONFIG;

///////// new add struct for filter /////////
typedef struct _VCI_FILTER_RECORD {
    DWORD ExtFrame;	 // 是否为扩展帧
    DWORD Start;
    DWORD End;
}VCI_FILTER_RECORD, *PVCI_FILTER_RECORD;
 
#define EXTERNC	extern "C"

// VCI_OpenDevice() 函数功能：打开一个指定类型和索引的设备，并且根据函数的返回值来表示是否打开成功
// DWORD：这是一个32位无符号整数的数据类型，通常在Windows编程中使用
// __stdcall：是一种标准的 WinAPI 调用约定，在函数调用结束后由被调用函数来清理堆栈
EXTERNC DWORD __stdcall VCI_OpenDevice(DWORD DeviceType,DWORD DeviceInd,DWORD Reserved);

EXTERNC DWORD __stdcall VCI_CloseDevice(DWORD DeviceType,DWORD DeviceInd);

EXTERNC DWORD __stdcall VCI_InitCAN(DWORD DeviceType, DWORD DeviceInd, DWORD CANInd, PVCI_INIT_CONFIG pInitConfig);

EXTERNC DWORD __stdcall VCI_ReadBoardInfo(DWORD DeviceType,DWORD DeviceInd,PVCI_BOARD_INFO pInfo);

EXTERNC DWORD __stdcall VCI_SetReference(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,DWORD RefType,PVOID pData);

EXTERNC ULONG __stdcall VCI_GetReceiveNum(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC DWORD __stdcall VCI_ClearBuffer(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC DWORD __stdcall VCI_StartCAN(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC DWORD __stdcall VCI_ResetCAN(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd);

EXTERNC ULONG __stdcall VCI_Transmit(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_OBJ pSend,ULONG Len);

EXTERNC ULONG __stdcall VCI_Receive(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_OBJ pReceive,ULONG Len,INT WaitTime);

/*------------------------------------------------其他补充函数及数据结构描述------------------------------------------------*/
#define EXTERNC	extern "C"

EXTERNC DWORD __stdcall VCI_UsbDeviceReset(DWORD DevType,DWORD DevIndex,DWORD Reserved);
EXTERNC DWORD __stdcall VCI_FindUsbDevice2(PVCI_BOARD_INFO pInfo);

#endif
