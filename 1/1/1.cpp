#include <iostream>

#include "CA.h"

int main()
{
	IUnknown *unknown = static_cast<IX*>(new CA());

	IX *ix;
	if (SUCCEEDED(unknown->QueryInterface(IID_IX, reinterpret_cast<void**>(&ix))))
	{
		ix->Fx();
		std::cout << ix->petrushka() << std::endl;
	}

	IY *iy;
	if (SUCCEEDED(unknown->QueryInterface(IID_IY, reinterpret_cast<void**>(&iy))))
		iy->Fy();
}