#pragma once

#include "books.h"

// CDeleteUpdate 对话框

class CDeleteUpdate : public CDialog
{
	DECLARE_DYNAMIC(CDeleteUpdate)

public:
	CDeleteUpdate(CWnd* pParent = NULL);   // 标准构造函数
	CDeleteUpdate(int,CString,int);
	virtual ~CDeleteUpdate();

// 对话框数据
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// //书名
	CString bookName;
	// 数量
	int bookNumber;
	//编号
	int bookId;
	BookList bookList;
	
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedSubmit();
};
