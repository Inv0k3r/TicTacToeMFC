// Wait.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Game.h"
#include "Wait.h"
#include "afxdialogex.h"


// CWait �Ի���

IMPLEMENT_DYNAMIC(CWait, CDialogEx)

CWait::CWait(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWait::IDD, pParent)
{

}

CWait::~CWait()
{
}

void CWait::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWait, CDialogEx)
END_MESSAGE_MAP()


// CWait ��Ϣ�������
