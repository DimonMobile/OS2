#pragma once

#include <Windows.h>

extern "C++" __declspec(dllexport) BOOL EdrCenterText(HDC hdc, PRECT prc, LPCWSTR pStr);
extern "C" __declspec(dllexport) int __stdcall AddNumbers(int p1, int p2);
extern "C" __declspec(dllexport) DWORD __stdcall GetTime();
