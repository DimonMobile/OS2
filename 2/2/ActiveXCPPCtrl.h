#pragma once

#define DISPID_TEST_METHOD (1025314)
#define DISPID_RADIUS_METHOD (1025315)

// ActiveXCPPCtrl.h : Declaration of the CActiveXCPPCtrl ActiveX Control class.


// CActiveXCPPCtrl : See ActiveXCPPCtrl.cpp for implementation.

class CActiveXCPPCtrl : public COleControl
{
	DECLARE_DYNCREATE(CActiveXCPPCtrl)

// Constructor
public:
	CActiveXCPPCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CActiveXCPPCtrl();

	DECLARE_OLECREATE_EX(CActiveXCPPCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CActiveXCPPCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CActiveXCPPCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CActiveXCPPCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg LONG TestMyMethod(LONG param1, LONG param2, BSTR param3);
	afx_msg LONG AreaByRadius(LONG par);

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidEventHandlerTest = 1L
	};

protected:
	void EventHandlerTest(LPCSTR name, LPCSTR surname, LONG age)
	{
		FireEvent(eventidEventHandlerTest, EVENT_PARAM(VTS_BSTR VTS_BSTR VTS_I4), name, surname, age);
	}
};

