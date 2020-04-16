#pragma once


// CCreate 对话框

class CCreate : public CDialogEx
{
	DECLARE_DYNAMIC(CCreate)

public:
	CCreate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCreate();
	char port[10];


// 对话框数据
	enum { IDD = IDD_CREATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancle();
};
