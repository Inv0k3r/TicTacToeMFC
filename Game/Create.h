#pragma once


// CCreate �Ի���

class CCreate : public CDialogEx
{
	DECLARE_DYNAMIC(CCreate)

public:
	CCreate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCreate();
	char port[10];


// �Ի�������
	enum { IDD = IDD_CREATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancle();
};
