#pragma once

#include <objbase.h>

interface IX :
	public IUnknown
{
	virtual void __stdcall Fx() = 0;
	virtual int __stdcall petrushka() = 0;
};

