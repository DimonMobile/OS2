// 2.cpp : Implementation of CMy2App and DLL registration.

#include "pch.h"
#include "framework.h"
#include "2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMy2App theApp;

const GUID CDECL _tlid = {0x0d292a76,0x7323,0x4553,{0x9a,0x85,0x88,0x15,0x95,0x5a,0x6f,0x7b}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMy2App::InitInstance - DLL initialization

BOOL CMy2App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CMy2App::ExitInstance - DLL termination

int CMy2App::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
