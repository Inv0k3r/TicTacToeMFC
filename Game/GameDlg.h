
// GameDlg.h : 头文件
//
#include "JoinDialog.h"
#include "Create.h"
#include "Wait.h"
#include <windows.h>
#pragma once


// CGameDlg 对话框
class CGameDlg : public CDialogEx
{
// 构造
public:
	CGameDlg(CWnd* pParent = NULL);	// 标准构造函数
// 自定义成员变量
	int map[3][3];//0 未落子 1 服务端落子 2 客户端落子

// 对话框数据
	enum { IDD = IDD_GAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private :
//socket相关

	WSADATA wsaData;
	SOCKET hServSock;//本机socket
	SOCKET hClntSock;//客户端Socket
	SOCKADDR_IN servAddr;//服务器地址
	SOCKADDR_IN clnAddr;//客户端地址
	char port[10];//端口号

	char pos[2];

	int Init();
	int Connect(char *ip, char *port);
	int Listen(char *port);
// 实现
	//棋盘操作
	bool turn;
	bool serv_clnt;//0:serv,1:clnt
	void check();
	void paint(bool x1_o0);
	int judge();//0:无结果 1:服务端胜 2: 客户端胜 3：平局
	bool printResult();//0:无结果 1：有结果
	//位图
	HBITMAP x, o;
//收发数据的函数
	//void sendPos(__in SOCKET s);
	//void recvPos(__in SOCKET s);
//多线程操作
	//DWORD WINAPI sendThread(LPVOID lParam);
	//DWORD WINAPI recvThread(LPVOID lParam);
//设置按钮不可用
	void disable();
//设置按钮可用
	void enable();
	
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedJoin();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
