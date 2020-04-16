// JoinDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Game.h"
#include "JoinDialog.h"
#include "afxdialogex.h"


// CJoinDialog �Ի���

IMPLEMENT_DYNAMIC(CJoinDialog, CDialogEx)

CJoinDialog::CJoinDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJoinDialog::IDD, pParent)
{

}

CJoinDialog::~CJoinDialog()
{
}

void CJoinDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJoinDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CJoinDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CJoinDialog ��Ϣ�������


void CJoinDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	CString temp;
	char *p;
	GetDlgItem(IDC_IP)->GetWindowText(temp);
	p = T2A(temp.GetBuffer(0));
	temp.ReleaseBuffer();
	strcpy(ip, p);
	GetDlgItem(IDC_PORT)->GetWindowText(temp);
	p = T2A(temp.GetBuffer(0));
	temp.ReleaseBuffer();
	strcpy(port,p);
	CDialogEx::OnOK();
}
