
#pragma once

class TPopupPanel : public CDialogEx
{
public:
	TPopupPanel();

	// �Ի�������
	enum { IDD = IDD_RIGHTPOPPANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
