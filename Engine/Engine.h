#pragma once

#include "Device.h"
#include "Command_Queue.h"
#include "SwapChain.h"
#include "RootSig.h"
#include "Shader.h"
#include "Mesh.h"
#include "ConstantBuffer.h"
class Engine
{
public:


	void Init(const WindowInfo& window);
	void Render();
	void ResizeWindow(int32 width,int32 height);

	void RenderBegin();
	void RenderEnd();

public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<Command_Queue> GetcmdQ() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapC() { return _swapChain; }
	shared_ptr<RootSig> GetRootSig() { return _rootsig; }
	shared_ptr<ConstantBuffer> GetConstantBuffer() { return _cb; }

private:
	//�׷��� ȭ�� ũ�� ����
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<Device> _device;
	shared_ptr<Command_Queue> _cmdQueue;
	shared_ptr<SwapChain> _swapChain;
	shared_ptr<RootSig> _rootsig;
	shared_ptr<ConstantBuffer> _cb;
	

};

