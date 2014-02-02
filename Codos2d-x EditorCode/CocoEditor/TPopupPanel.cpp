
#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "CocoEditor.h"
#endif

#include "TPopupPanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(TPopupPanel, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &TPopupPanel::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &TPopupPanel::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()

TPopupPanel::TPopupPanel() : CDialogEx(TPopupPanel::IDD)
{
}

void TPopupPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void TPopupPanel::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}

void TPopupPanel::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	CSliderCtrl   *pSlidCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	int size = pSlidCtrl->GetPos();
	printf("%d\n", size);
	*pResult = 0;
}