// Create.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Game.h"
#include "Create.h"
#include "afxdialogex.h"


// CCreate �Ի���

IMPLEMENT_DYNAMIC(CCreate, CDialogEx)

CCreate::CCreate(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCreate::IDD, pParent)
{

}

CCreate::~CCreate()
{
}

void CCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCreate, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCreate::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCLE, &CCreate::OnBnClickedCancle)
END_MESSAGE_MAP()


// CCreate ��Ϣ�������




void CCreate::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString temp;
	char *p;
	GetDlgItem(IDC_PORT)->GetWindowText(temp);
	USES_CONVERSION;
	p = T2A(temp.GetBuffer(0));
	temp.ReleaseBuffer();
	strcpy(port,p);
	CDialogEx::OnOK();
}


void CCreate::OnBnClickedCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
