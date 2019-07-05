// DeleteUpdate.cpp : 实现文件
//

#include "stdafx.h"
#include "book.h"
#include "DeleteUpdate.h"
#include "ManageDlg.h"


// CDeleteUpdate 对话框

IMPLEMENT_DYNAMIC(CDeleteUpdate, CDialog)

CDeleteUpdate::CDeleteUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteUpdate::IDD, pParent)
	,bookId(0)
	, bookName()
	, bookNumber()
{

}

CDeleteUpdate::CDeleteUpdate(int id,CString bn,int bnum)
: CDialog(CDeleteUpdate::IDD, NULL)
,bookId(id)
, bookName(bn)
, bookNumber(bnum)
{
	
}

CDeleteUpdate::~CDeleteUpdate()
{
}

void CDeleteUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, bookName);
	DDX_Text(pDX, IDC_EDIT_NUMBER, bookNumber);
}


BEGIN_MESSAGE_MAP(CDeleteUpdate, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CDeleteUpdate::OnBnClickedCancel)
	ON_BN_CLICKED(IDSUBMIT, &CDeleteUpdate::OnBnClickedSubmit)
END_MESSAGE_MAP()


// CDeleteUpdate 消息处理程序

BOOL CDeleteUpdate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDeleteUpdate::OnBnClickedCancel()
{
	OnCancel();
}

void CDeleteUpdate::OnBnClickedSubmit()
{
	if(bookId==0){
		Book book;
		UpdateData(TRUE);
		UpdateData(FALSE);
		book.name=bookName.GetBuffer(0);
		book.number=bookNumber;
		bookList.addBook(book);
	}
	else{
		Book book;
		UpdateData(TRUE);
		UpdateData(FALSE);
		book.id=bookId;
		book.name=bookName.GetBuffer(0);
		book.number=bookNumber;
		bookList.updateBook(book);
	}
	OnCancel();
	
}
