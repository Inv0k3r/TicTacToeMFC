// Create.cpp : 实现文件
//

#include "stdafx.h"
#include "Game.h"
#include "Create.h"
#include "afxdialogex.h"


// CCreate 对话框

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


// CCreate 消息处理程序




void CCreate::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
}
