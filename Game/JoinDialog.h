#pragma once


// CJoinDialog 对话框

class CJoinDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CJoinDialog)

public:
	CJoinDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJoinDialog();

// 对话框数据
	enum { IDD = IDD_JOIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public :
	char ip[10];
	char port[20];
	afx_msg void OnBnClickedOk();
};
