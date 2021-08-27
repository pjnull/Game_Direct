#pragma once


#include<Windows.h>
#include<tchar.h>
#include<memory>
#include<string>
#include<vector>
#include<array>
#include<list>
#include<map>
using namespace std;

#include"d3dx12.h"
#include<d3d12.h>
#include<wrl.h>
#include<d3dcompiler.h>
#include<dxgi.h>
#include<DirectXMath.h>
#include<DirectXPackedVector.h>
#include<DirectXColors.h>
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;

#pragma comment(lib,"d3d12")
#pragma comment(lib,"dxgi")
#pragma comment(lib,"dxguid")
#pragma comment(lib,"d3dcompiler")

using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using unit8		= unsigned __int8;
using unit16	= unsigned __int16;
using unit32	= unsigned __int32;
using unit64	= unsigned __int64;
using Vec2		= XMFLOAT2;
using Vec3		= XMFLOAT3;
using Vec4		= XMFLOAT4;
using Matrox	= XMMATRIX;

struct  WindowInfo
{
	HWND hwnd;
	int32 width;
	int32 height;
	bool windowed;
};

extern unique_ptr<class Engine> GEngine;


void HelloEngine();

