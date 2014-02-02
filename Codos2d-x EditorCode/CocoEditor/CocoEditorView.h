
// CocoEditorView.h : CCocoEditorView 类的接口
//

#pragma once


class CCocoEditorView : public CView
{
protected: // 仅从序列化创建
	CCocoEditorView();
	DECLARE_DYNCREATE(CCocoEditorView)

// 特性
public:
	CCocoEditorDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCocoEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool IsSatrt;
// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMouseMove(UINT i, CPoint p);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CocoEditorView.cpp 中的调试版本
inline CCocoEditorDoc* CCocoEditorView::GetDocument() const
   { return reinterpret_cast<CCocoEditorDoc*>(m_pDocument); }
#endif

