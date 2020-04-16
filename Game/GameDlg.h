
// GameDlg.h : ͷ�ļ�
//
#include "JoinDialog.h"
#include "Create.h"
#include "Wait.h"
#include <windows.h>
#pragma once


// CGameDlg �Ի���
class CGameDlg : public CDialogEx
{
// ����
public:
	CGameDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Զ����Ա����
	int map[3][3];//0 δ���� 1 ��������� 2 �ͻ�������

// �Ի�������
	enum { IDD = IDD_GAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private :
//socket���

	WSADATA wsaData;
	SOCKET hServSock;//����socket
	SOCKET hClntSock;//�ͻ���Socket
	SOCKADDR_IN servAddr;//��������ַ
	SOCKADDR_IN clnAddr;//�ͻ��˵�ַ
	char port[10];//�˿ں�

	char pos[2];

	int Init();
	int Connect(char *ip, char *port);
	int Listen(char *port);
// ʵ��
	//���̲���
	bool turn;
	bool serv_clnt;//0:serv,1:clnt
	void check();
	void paint(bool x1_o0);
	int judge();//0:�޽�� 1:�����ʤ 2: �ͻ���ʤ 3��ƽ��
	bool printResult();//0:�޽�� 1���н��
	//λͼ
	HBITMAP x, o;
//�շ����ݵĺ���
	//void sendPos(__in SOCKET s);
	//void recvPos(__in SOCKET s);
//���̲߳���
	//DWORD WINAPI sendThread(LPVOID lParam);
	//DWORD WINAPI recvThread(LPVOID lParam);
//���ð�ť������
	void disable();
//���ð�ť����
	void enable();
	
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
