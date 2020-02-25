#pragma once

#include "IX.h"
#include "IY.h"

//  IID
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82} };
// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
static const IID IID_IY =
{ 0x32bb8321, 0xb41b, 0x11cf,
{0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82} };

class CA : public IX, public IY
{
	virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;
	virtual ULONG __stdcall AddRef(void) override;
	virtual ULONG __stdcall Release(void) override;

	virtual void __stdcall Fx() override;
	virtual int __stdcall petrushka() override;
	virtual void __stdcall Fy() override;
};

