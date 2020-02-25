#include "CA.h"

#include <iostream>

HRESULT __stdcall CA::QueryInterface(REFIID riid, void** ppvObject)
{
	if (riid == IID_IX)
		*ppvObject = static_cast<IX*>(this);
	else if (riid == IID_IY)
		*ppvObject = static_cast<IY*>(this);
	else
		*ppvObject = nullptr;

	if (ppvObject)
		return S_OK;

	return E_NOINTERFACE;
}

ULONG __stdcall CA::AddRef(void)
{
	return 0;
}

ULONG __stdcall CA::Release(void)
{
	return 0;
}

void __stdcall CA::Fx()
{
	std::cout << "Hello from Fx()" << std::endl;
}

void __stdcall CA::Fy()
{
	std::cout << "Hello from Fy()" << std::endl;
}

int __stdcall CA::petrushka()
{
	return rand() % 100;
}
