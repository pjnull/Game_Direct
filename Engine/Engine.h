#pragma once

#include "Device.h"
#include "Command_Queue.h"
#include "SwapChain.h"
#include "RootSig.h"
#include "Shader.h"
#include "Mesh.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"
#include "Texture.h"
#include "Depth_Stencil_Buffer.h"
#include "Input.h"
#include "Timer.h"
class Engine
{
public:


	void Init(const WindowInfo& window);
	void Render();
	void ResizeWindow(int32 width,int32 height);

	void RenderBegin();
	void RenderEnd();

	void Update();

public:
	shared_ptr<Device> GetDevice() { return _device; }
	shared_ptr<Command_Queue> GetcmdQ() { return _cmdQueue; }
	shared_ptr<SwapChain> GetSwapC() { return _swapChain; }
	shared_ptr<RootSig> GetRootSig() { return _rootsig; }
	shared_ptr<ConstantBuffer> GetConstantBuffer() { return _cb; }
	shared_ptr<TableDescriptorHeap> GetTableDecHeap() { return _tableDescHeap; }
	shared_ptr<Depth_Stencil_Buffer>GetDepthStencilBuffer() { return _depthStencilBuffer; }
	
	shared_ptr<Input>GetInput() { return _input; }
	shared_ptr<Timer>GetTimer() { return _timer; }

private:
	void ShowFps();
private:
	//그려질 화면 크기 관련
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<Device> _device = make_shared< Device>();
	shared_ptr<Command_Queue> _cmdQueue = make_shared< Command_Queue>();
	shared_ptr<SwapChain> _swapChain = make_shared< SwapChain>();
	shared_ptr<RootSig> _rootsig = make_shared<RootSig>();
	shared_ptr<ConstantBuffer> _cb = make_shared<ConstantBuffer>();
	shared_ptr<TableDescriptorHeap> _tableDescHeap = make_shared<TableDescriptorHeap>();
	shared_ptr<Depth_Stencil_Buffer>_depthStencilBuffer = make_shared<Depth_Stencil_Buffer>();
	
	shared_ptr<Input>_input = make_shared<Input>();
	shared_ptr<Timer>_timer = make_shared<Timer>();
};

