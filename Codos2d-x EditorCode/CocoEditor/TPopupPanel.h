
#pragma once

class TPopupPanel : public CDialogEx
{
public:
	TPopupPanel();

	// 对话框数据
	enum { IDD = IDD_RIGHTPOPPANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
