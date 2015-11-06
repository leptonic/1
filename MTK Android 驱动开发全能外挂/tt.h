// tt.h : main header file for the TT application
//

#if !defined(AFX_TT_H__A66E2ED2_3CFF_41B8_B43A_DF5BD4AAB878__INCLUDED_)
#define AFX_TT_H__A66E2ED2_3CFF_41B8_B43A_DF5BD4AAB878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTtApp:
// See tt.cpp for the implementation of this class
//

class CTtApp : public CWinApp
{
public:
	CTtApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTtApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTtApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TT_H__A66E2ED2_3CFF_41B8_B43A_DF5BD4AAB878__INCLUDED_)
