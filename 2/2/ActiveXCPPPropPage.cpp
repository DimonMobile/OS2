// ActiveXCPPPropPage.cpp : Implementation of the CActiveXCPPPropPage property page class.

#include "pch.h"
#include "framework.h"
#include "2.h"
#include "ActiveXCPPPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXCPPPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CActiveXCPPPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CActiveXCPPPropPage, "MFCACTIVEXCONT.ActiveXCPPPropPage.1",
	0x12acc61d,0x897f,0x4499,0x84,0xd9,0xf1,0x7d,0xdc,0x18,0x8f,0x0e)

// CActiveXCPPPropPage::CActiveXCPPPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CActiveXCPPPropPage

BOOL CActiveXCPPPropPage::CActiveXCPPPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MY2_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CActiveXCPPPropPage::CActiveXCPPPropPage - Constructor

CActiveXCPPPropPage::CActiveXCPPPropPage() :
	COlePropertyPage(IDD, IDS_MY2_PPG_CAPTION)
{
}

// CActiveXCPPPropPage::DoDataExchange - Moves data between page and properties

void CActiveXCPPPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CActiveXCPPPropPage message handlers
