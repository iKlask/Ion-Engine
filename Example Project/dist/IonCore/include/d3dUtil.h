//***************************************************************************************
// d3dUtil.h by Frank Luna (C) 2011 All Rights Reserved.
//***************************************************************************************

#include "Enum.h"

#ifndef D3DUTIL_H
#define D3DUTIL_H


// Convenience macro for releasing COM objects.
#define ReleaseAndDeleteCOMobject(x) { if(x){ x->Release(); x = 0; } }

// Hack to pass a Vect as a array of floats (only needed for ClearRenderTargetView)
#define VasA(v) { &v[x] }


#endif // D3DUTIL_H