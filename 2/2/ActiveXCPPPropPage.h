#pragma once

// ActiveXCPPPropPage.h : Declaration of the CActiveXCPPPropPage property page class.


// CActiveXCPPPropPage : See ActiveXCPPPropPage.cpp for implementation.

class CActiveXCPPPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CActiveXCPPPropPage)
	DECLARE_OLECREATE_EX(CActiveXCPPPropPage)

// Constructor
public:
	CActiveXCPPPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_MY2 };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

