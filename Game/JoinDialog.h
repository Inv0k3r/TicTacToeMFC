#pragma once


// CJoinDialog �Ի���

class CJoinDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CJoinDialog)

public:
	CJoinDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJoinDialog();

// �Ի�������
	enum { IDD = IDD_JOIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public :
	char ip[10];
	char port[20];
	afx_msg void OnBnClickedOk();
};
