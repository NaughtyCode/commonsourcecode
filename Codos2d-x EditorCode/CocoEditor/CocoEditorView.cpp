
// CocoEditorView.cpp : CCocoEditorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CocoEditor.h"
#endif
#include "TPopupPanel.h"
#include "CocoEditorDoc.h"
#include "CocoEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCocoEditorView

IMPLEMENT_DYNCREATE(CCocoEditorView, CView)

BEGIN_MESSAGE_MAP(CCocoEditorView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCocoEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CCocoEditorView 构造/析构

CCocoEditorView::CCocoEditorView()
{
	IsSatrt = false;
}

CCocoEditorView::~CCocoEditorView()
{
}

BOOL CCocoEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCocoEditorView 绘制

void CCocoEditorView::OnDraw(CDC* /*pDC*/)
{
	CCocoEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}

// CCocoEditorView 打印


void CCocoEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCocoEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCocoEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CCocoEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CCocoEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	if (!IsSatrt){
		this->SetRedraw(FALSE);
		CreateRenderEngine((int)this->GetSafeHwnd());
		IsSatrt = true;
	}
	else{
		ClientToScreen(&point);
		OnContextMenu(this, point);
		TPopupPanel panel;
		panel.DoModal();
	}
}

void CCocoEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
}

// CCocoEditorView 诊断

#ifdef _DEBUG
void CCocoEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CCocoEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCocoEditorDoc* CCocoEditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCocoEditorDoc)));
	return (CCocoEditorDoc*)m_pDocument;
}
#endif //_DEBUG

// CCocoEditorView 消息处理程序

void CCocoEditorView::OnMouseMove(UINT i, CPoint p)
{
	printf("(%d,%d)\n", p.x, p.y);
}

