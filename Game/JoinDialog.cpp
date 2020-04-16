// JoinDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "Game.h"
#include "JoinDialog.h"
#include "afxdialogex.h"


// CJoinDialog 对话框

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


// CJoinDialog 消息处理程序


void CJoinDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
