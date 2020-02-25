// ActiveXCPPCtrl.cpp : Implementation of the CActiveXCPPCtrl ActiveX Control class.

#include "pch.h"
#include "framework.h"
#include "2.h"
#include "ActiveXCPPCtrl.h"
#include "ActiveXCPPPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXCPPCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CActiveXCPPCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CActiveXCPPCtrl, COleControl)
	DISP_FUNCTION_ID(CActiveXCPPCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CActiveXCPPCtrl, "TestMyMethod", DISPID_TEST_METHOD, TestMyMethod, VT_I4, VTS_I4 VTS_I4 VTS_BSTR)
	DISP_FUNCTION_ID(CActiveXCPPCtrl, "AreaByRadius", DISPID_RADIUS_METHOD, AreaByRadius, VT_I4, VTS_I4)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CActiveXCPPCtrl, COleControl)
	EVENT_CUSTOM_ID("EventHandlerTest", eventidEventHandlerTest, EventHandlerTest, VTS_BSTR VTS_BSTR VTS_I4)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CActiveXCPPCtrl, 1)
	PROPPAGEID(CActiveXCPPPropPage::guid)
END_PROPPAGEIDS(CActiveXCPPCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CActiveXCPPCtrl, "MFCACTIVEXCONTRO.ActiveXCPPCtrl.1",
	0x7879f7c2,0x53dc,0x4d1f,0xa4,0x8e,0x6b,0x70,0x5c,0xa6,0x6f,0x56)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CActiveXCPPCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_DMy2 = {0x6ad06cf9,0xb4d0,0x45f0,{0x80,0x2b,0x71,0x6e,0x44,0xf7,0x8d,0x32}};
const IID IID_DMy2Events = {0x65244d07,0x6fed,0x4a8d,{0x9e,0x15,0x9e,0x3c,0x1c,0x18,0x1e,0x4f}};

// Control type information

static const DWORD _dwMy2OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CActiveXCPPCtrl, IDS_MY2, _dwMy2OleMisc)

// CActiveXCPPCtrl::CActiveXCPPCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CActiveXCPPCtrl

BOOL CActiveXCPPCtrl::CActiveXCPPCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MY2,
			IDB_MY2,
			afxRegApartmentThreading,
			_dwMy2OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CActiveXCPPCtrl::CActiveXCPPCtrl - Constructor

CActiveXCPPCtrl::CActiveXCPPCtrl()
{
	InitializeIIDs(&IID_DMy2, &IID_DMy2Events);
	// TODO: Initialize your control's instance data here.
}

// CActiveXCPPCtrl::~CActiveXCPPCtrl - Destructor

CActiveXCPPCtrl::~CActiveXCPPCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CActiveXCPPCtrl::OnDraw - Drawing function

void CActiveXCPPCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CActiveXCPPCtrl::DoPropExchange - Persistence support

void CActiveXCPPCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CActiveXCPPCtrl::OnResetState - Reset control to default state

void CActiveXCPPCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CActiveXCPPCtrl::AboutBox - Display an "About" box to the user

void CActiveXCPPCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MY2);
	dlgAbout.DoModal();
}

LONG CActiveXCPPCtrl::TestMyMethod(LONG param1, LONG param2, BSTR param3)
{
	return (LONG)param1 * param1 * 3.141592;
}

LONG CActiveXCPPCtrl::AreaByRadius(LONG par)
{
	return (LONG)3.141592 * par * par;
}

// CActiveXCPPCtrl message handlers
