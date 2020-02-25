#include "External.h"

#include <ctime>

BOOL EdrCenterText(HDC hdc, PRECT prc, LPCWSTR pStr)
{
	int iLength;
	SIZE size;
	iLength = wcslen(pStr);
	GetTextExtentPoint32(hdc, pStr, iLength, &size);
	return TextOut(hdc, (prc->right - prc->left - size.cx) / 2, (prc->bottom - prc->top - size.cy) / 2, pStr, iLength);
}

int __stdcall AddNumbers(int p1, int p2)
{
	return p1 + p2;
}

DWORD __stdcall GetTime()
{
	return time(nullptr);
}