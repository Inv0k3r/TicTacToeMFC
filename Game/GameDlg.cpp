
// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Game.h"
#include "GameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameDlg �Ի���




CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGameDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CREATE, &CGameDlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_JOIN, &CGameDlg::OnBnClickedJoin)
	ON_BN_CLICKED(IDC_BUTTON2, &CGameDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGameDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGameDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CGameDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CGameDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGameDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CGameDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CGameDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������

BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 3;j ++)
			map[i][j] = 0;
	turn = false;
	serv_clnt = 0;
	//��ʼ����Ϸ����
	//����ͼ
	//��ťͼƬ
	HBITMAP back; 
	
	back = LoadBitmap(AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDB_BUTTON)); 

	((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON2))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON3))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON4))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON5))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON6))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON7))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON8))->SetBitmap(back);
	((CButton *)GetDlgItem(IDC_BUTTON9))->SetBitmap(back);
	//IDB_BITMAP1Ϊλͼ��ԴID ��IDC_BT_BYTEΪ��ťID
	x = LoadBitmap(AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDB_X)); 
	o = LoadBitmap(AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDB_O)); 
	//��ʼ��socket
	Init();
	GetDlgItem(IDC_FOCUS)->SetFocus();

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ʼ���� ���ؽ����1��wsa����2��socket����0������
int CGameDlg::Init(){
	if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
		return 1;
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if(hServSock == INVALID_SOCKET)
		return 2;
	return 0;
}

int CGameDlg::Connect(char *ip, char *port){
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ip);
	servAddr.sin_port = htons(atoi(port));
	if(connect(hServSock,(SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		return 1;
	return 0;
}

//1: bind error 2: listen error
int CGameDlg::Listen(char *port){
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(port));
	if(bind(hServSock, (SOCKADDR *)&servAddr,sizeof(servAddr)) == SOCKET_ERROR)
		return 1;
	if(listen(hServSock, 5) == SOCKET_ERROR)
		return 2;
}

void CGameDlg::OnBnClickedCreate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCreate d;
	if(d.DoModal() == IDOK){
		char *p = d.port;
		Listen(p);
		int szClntAddr = sizeof(clnAddr);
		/*if(w.DoModal() == IDCANCEL)
			return;*/
		hClntSock = accept(hServSock, (SOCKADDR*)&clnAddr, &szClntAddr);
		//w.DestroyWindow();
		turn = true;
		MessageBox(_T("Game Start!"));
		GetDlgItem(IDC_CREATE)->EnableWindow(FALSE);
		GetDlgItem(IDC_JOIN)->EnableWindow(FALSE);
		serv_clnt = 0;
	}
}

void CGameDlg::OnBnClickedJoin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CJoinDialog d;
	if(d.DoModal() == IDOK){
		char *a, *b;
		a = d.ip;
		b = d.port;
		Connect(a,b);
		connect(hServSock,(SOCKADDR *)&servAddr, sizeof(servAddr));
		MessageBox(_T("Game Start!"));
		GetDlgItem(IDC_CREATE)->EnableWindow(FALSE);
		GetDlgItem(IDC_JOIN)->EnableWindow(FALSE);
		serv_clnt = 1;
		recv(hServSock,pos,2,0);
		paint(1);
		turn = true;
	}

}
int CGameDlg::judge(){//0:�޽�� 1:�����ʤ 2: �ͻ���ʤ 3��ƽ��
	for(int i = 0; i < 3;i ++){
		if(map[i][0] == map[i][1]&& map[i][1] == map[i][2] && map[i][2] != 0){
			if(map[i][0] == 1)
				return 1;
			else
				return 2;
		}
		else if(map[0][i] == map[1][i]&& map[1][i] == map[2][i] && map[2][i] != 0){
			if(map[0][i] == 1)
				return 1;
			else
				return 2;
		}
		
	}
	if(map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[2][2] != 0)
		if(map[0][0] == 1)
			return 1;
		else
			return 2;
	else if(map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[2][0] != 0)
		if(map[0][2] == 1)
			return 1;
		else
			return 2;
	for(int i = 0; i < 3;i ++){
		for(int j = 0; j < 3;j ++){
			if(map[i][j] == 0)
				return 0;
		}
	}
	return 3;
}

void CGameDlg::disable(){
	((CButton *)GetDlgItem(IDC_BUTTON1))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON2))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON7))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(FALSE);
}

void CGameDlg::enable(){
	((CButton *)GetDlgItem(IDC_BUTTON1))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON2))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON3))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON4))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON5))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON6))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON7))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(TRUE);
	((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(TRUE);
}

void CGameDlg::paint(bool x1_o0){
	int id = 0;
	int xPos = pos[0] - '0';
	int yPos = pos[1] - '0';
	if(xPos == 0 && yPos == 0)
		id = 1;
	else if(xPos == 0 && yPos == 1)
		id = 2;
	else if(xPos == 0 && yPos == 2)
		id = 3;
	else if(xPos == 1 && yPos == 0)
		id = 4;
	else if(xPos == 1 && yPos == 1)
		id = 5;
	else if(xPos == 1 && yPos == 2)
		id = 6;
	else if(xPos == 2 && yPos == 0)
		id = 7;
	else if(xPos == 2 && yPos == 1)
		id = 8;
	else if(xPos == 2 && yPos == 2)
		id = 9;
	HBITMAP *f;
	if(x1_o0 == 0){
		f = &x;
		map[xPos][yPos] = 2;
	}
	else{
		f = &o;
		map[xPos][yPos] = 1;
	}
	switch(id){
	case 1: ((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(*f);break;
	case 2: ((CButton *)GetDlgItem(IDC_BUTTON2))->SetBitmap(*f);break;
	case 3: ((CButton *)GetDlgItem(IDC_BUTTON3))->SetBitmap(*f);break;
	case 4: ((CButton *)GetDlgItem(IDC_BUTTON4))->SetBitmap(*f);break;
	case 5: ((CButton *)GetDlgItem(IDC_BUTTON5))->SetBitmap(*f);break;
	case 6: ((CButton *)GetDlgItem(IDC_BUTTON6))->SetBitmap(*f);break;
	case 7: ((CButton *)GetDlgItem(IDC_BUTTON7))->SetBitmap(*f);break;
	case 8: ((CButton *)GetDlgItem(IDC_BUTTON8))->SetBitmap(*f);break;
	case 9: ((CButton *)GetDlgItem(IDC_BUTTON9))->SetBitmap(*f);break;
	}
}
//0:�޽�� 1���н��
bool CGameDlg::printResult(){
	switch(judge()){
	case 1:{
		if(serv_clnt == 0)
			MessageBox(_T("You Win!"));
		else
			MessageBox(_T("You Lose..."));
		disable();
		return true;
		   }break;
	case 2:{		
		if(serv_clnt == 0)
		   MessageBox(_T("You Lose..."));
		else
			MessageBox(_T("You Win!"));
		disable();
		return true;
		   }break;
	case 3:{
		MessageBox(_T("play even!"));
		disable();
		return true;
		   }break;
	}
	return false;
}

void CGameDlg::check(){
	bool flag = false;
	if(serv_clnt == 0){
		if(turn){
			if(map[pos[0] - '0'][pos[1] - '0'] == 0){
				paint(1);
				send(hClntSock,pos,2,0);
				if(printResult() == true)
					return;
				turn = false;
				flag = true;
			}
		}
		if(flag == true){
			char temp[2];
			recv(hClntSock,pos,2,0);
			paint(0);
			if(printResult() == true)
				return;
			turn = true;
		}
	}else{
		if(turn){
			if(map[pos[0] - '0'][pos[1] - '0'] == 0){
				paint(0);
				send(hServSock,pos,2,0);
				if(printResult() == true)
					return;
				turn = false;
				flag = true;
			}
		}
		if(flag == true) {
			recv(hServSock,pos,2,0);
			paint(1);
			if(printResult() == true)
				return;
			turn = true;
		}
		//if(judge() == 3)
		//	send(hServSock, "en", 2, 0);
	}
}

//DWORD WINAPI  CGameDlg::sendThread(LPVOID lParam){
//	//send(s,pos,2,0);
//	return 0L;
//}
//
//DWORD WINAPI  CGameDlg::recvThread(LPVOID lParam){
//	//recv(hClntSock,pos,2,0);
//	return 0L;
//}
//
//void CGameDlg::sendPos(__in SOCKET s){
//	/*int a = 1;
//	HANDLE hThread1 = CreateThread(NULL, 0, &CGameDlg::sendThread, &a, 0, NULL);
//	CloseHandle(hThread1);*/
//}
//
//void CGameDlg::recvPos(__in SOCKET s){
//	//int a = 1;
//	//HANDLE hThread1 = CreateThread(NULL, 0, &CGameDlg::recvThread, &a, 0, NULL);
//	//CloseHandle(hThread1);
//}

void CGameDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '0';
	pos[1] = '0';
	check();
}

void CGameDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '0';
	pos[1] = '1';
	check();
}


void CGameDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '0';
	pos[1] = '2';
	check();
}


void CGameDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '1';
	pos[1] = '0';
	check();
}


void CGameDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '1';
	pos[1] = '1';
	check();
}


void CGameDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '1';
	pos[1] = '2';
	check();
}


void CGameDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '2';
	pos[1] = '0';
	check();
}


void CGameDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '2';
	pos[1] = '1';
	check();
}


void CGameDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_FOCUS)->SetFocus();
	pos[0] = '2';
	pos[1] = '2';
	check();
}
