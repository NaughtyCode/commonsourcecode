
// CocoEditorView.h : CCocoEditorView ��Ľӿ�
//

#pragma once


class CCocoEditorView : public CView
{
protected: // �������л�����
	CCocoEditorView();
	DECLARE_DYNCREATE(CCocoEditorView)

// ����
public:
	CCocoEditorDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CCocoEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool IsSatrt;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseMove(UINT i, CPoint p);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CocoEditorView.cpp �еĵ��԰汾
inline CCocoEditorDoc* CCocoEditorView::GetDocument() const
   { return reinterpret_cast<CCocoEditorDoc*>(m_pDocument); }
#endif

