#pragma once
#include "afxcmn.h"
#include "books.h"

// CManageDlg 对话框

class CManageDlg : public CDialog
{
	DECLARE_DYNAMIC(CManageDlg)
 
public:
	CManageDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManageDlg();

// 对话框数据
	enum { IDD = IDD_MANAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	// //图书列表
	CListCtrl bookList;
	
	BookList books;
	
	void showAll();

	afx_msg void OnBnClickedButtonSearch();
	
	virtual BOOL OnInitDialog();
	
	//图书编号
	CString bookId;
	afx_msg void OnBnClickedButtonShowall();
	afx_msg void OnBnClickedButtonAddbook();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonUpdate();
};
