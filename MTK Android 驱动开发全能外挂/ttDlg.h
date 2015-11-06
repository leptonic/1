// ttDlg.h : header file
//

#if !defined(AFX_TTDLG_H__D92D8C7D_7A91_483B_9083_1D5E488CBE6A__INCLUDED_)
#define AFX_TTDLG_H__D92D8C7D_7A91_483B_9083_1D5E488CBE6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTtDlg dialog

class CTtDlg : public CDialog
{
// Construction
public:
	CTtDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTtDlg)
	enum { IDD = IDD_TT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTtDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton14();
	afx_msg void OnButton15();
	afx_msg void OnButton16();
	afx_msg void OnButton17();
	afx_msg void OnButton18();
	afx_msg void OnButton19();
	afx_msg void OnButton20();
	afx_msg void OnButton22();
	afx_msg void OnButton23();
	afx_msg void OnButton24();
	afx_msg void OnButton25();
	afx_msg void OnButton26();
	afx_msg void OnButton27();
	afx_msg void OnButton28();
	afx_msg void OnButton29();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTDLG_H__D92D8C7D_7A91_483B_9083_1D5E488CBE6A__INCLUDED_)
