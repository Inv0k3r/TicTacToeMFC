#pragma once


// CWait �Ի���

class CWait : public CDialogEx
{
	DECLARE_DYNAMIC(CWait)

public:
	CWait(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWait();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
