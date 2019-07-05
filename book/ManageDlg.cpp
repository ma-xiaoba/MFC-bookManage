// ManageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "book.h"
#include "DeleteUpdate.h"
#include "ManageDlg.h"
#include <map>
#include <string>
#include <sstream>

// CManageDlg 对话框

IMPLEMENT_DYNAMIC(CManageDlg, CDialog)

CManageDlg::CManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManageDlg::IDD, pParent)
	, bookId(_T(""))
{
	

}

CManageDlg::~CManageDlg()
{
}

void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_BOOK, bookList);
	DDX_Text(pDX, IDC_EDIT_SEARCH, bookId);
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CManageDlg::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_SHOWALL, &CManageDlg::OnBnClickedButtonShowall)
	ON_BN_CLICKED(IDC_BUTTON_ADDBOOK, &CManageDlg::OnBnClickedButtonAddbook)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CManageDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CManageDlg::OnBnClickedButtonUpdate)
END_MESSAGE_MAP()


// CManageDlg 消息处理程序


BOOL CManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	bookList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);

	bookList.InsertColumn(0,"编号", LVCFMT_LEFT, 100);

	bookList.InsertColumn(1, "书名", LVCFMT_LEFT, 200);

	bookList.InsertColumn(2, "数量", LVCFMT_LEFT, 100);
	showAll();

	return TRUE;
}

void CManageDlg::OnBnClickedButtonSearch()
{
	UpdateData(TRUE);
	UpdateData(FALSE);

	Book book=books.search(_ttoi(bookId));
	bookList.DeleteAllItems();
	if(book.id!=0){
		CString id,number;

		bookList.InsertItem(0,""); 
		
		id.Format("%d",book.id);

		bookList.SetItemText(0, 0,id);

		bookList.SetItemText(0, 1,book.name.c_str());

		number.Format("%d",book.number);

		bookList.SetItemText(0, 2, number);
	}

}

void CManageDlg::showAll(){


	map<int, Book>::iterator iter;
	map<int, Book> bls=books.showAll();

	int i=0;

	CString id,number;

	for(iter = bls.begin(); iter != bls.end(); iter++){

		bookList.InsertItem(i,""); 

		id.Format("%d",iter->second.id);

		bookList.SetItemText(i, 0,id);

		bookList.SetItemText(i, 1,iter->second.name.c_str());

		number.Format("%d",iter->second.number);

		bookList.SetItemText(i, 2, number);
	}
}

void CManageDlg::OnBnClickedButtonShowall()
{

	bookList.DeleteAllItems();
	showAll();
}


//添加图书
void CManageDlg::OnBnClickedButtonAddbook()
{
	CDeleteUpdate deleteUpdate;
	deleteUpdate.DoModal();
	if(deleteUpdate.m_hWnd==NULL){
		bookList.DeleteAllItems();
		showAll();
	}
}

//删除图书
void CManageDlg::OnBnClickedButtonDelete()
{
	bool state;
	for(int i = 0;i < bookList.GetItemCount();i++) {
		state = bookList.GetCheck(i);

		if(state == TRUE) {
			books.deleteBook(_ttoi(bookList.GetItemText(i,0)));	
		}
	}
	bookList.DeleteAllItems();
	showAll();
}

void CManageDlg::OnBnClickedButtonUpdate()
{
	bool state;
	int checkCount=0;
	int n;
	for(int i = 0;i < bookList.GetItemCount();i++) {
		state = bookList.GetCheck(i);
		if(state == TRUE) {
			n=i;		
			checkCount++;
		}
	}


	if(checkCount==1){

		CDeleteUpdate deleteUpdate(_ttoi(bookList.GetItemText(n,0)),bookList.GetItemText(n,1),_ttoi(bookList.GetItemText(n,2)));
		deleteUpdate.DoModal();
		if(deleteUpdate.m_hWnd==NULL){
			bookList.DeleteAllItems();
			showAll();
		}

	}
	else if(checkCount>1){
		MessageBox("只能选择一行");
	}
}


