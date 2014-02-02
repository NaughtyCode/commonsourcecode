
// CocoEditorView.cpp : CCocoEditorView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCocoEditorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CCocoEditorView ����/����

CCocoEditorView::CCocoEditorView()
{
	IsSatrt = false;
}

CCocoEditorView::~CCocoEditorView()
{
}

BOOL CCocoEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCocoEditorView ����

void CCocoEditorView::OnDraw(CDC* /*pDC*/)
{
	CCocoEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

// CCocoEditorView ��ӡ


void CCocoEditorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCocoEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCocoEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCocoEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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

// CCocoEditorView ���

#ifdef _DEBUG
void CCocoEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CCocoEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCocoEditorDoc* CCocoEditorView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCocoEditorDoc)));
	return (CCocoEditorDoc*)m_pDocument;
}
#endif //_DEBUG

// CCocoEditorView ��Ϣ�������

void CCocoEditorView::OnMouseMove(UINT i, CPoint p)
{
	printf("(%d,%d)\n", p.x, p.y);
}

