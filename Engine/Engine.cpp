#include "pch.h"
#include "Engine.h"



void Engine::Init(const WindowInfo& window)
{
	_window = window;
	ResizeWindow(window.width, window.height);
	_viewport = { 0,0,static_cast<FLOAT>(window.width),static_cast<FLOAT>(window.height),0.0f,1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, window.width, window.height);
	
	
	_device = make_shared< Device>();
	_cmdQueue = make_shared< Command_Queue>();
	_swapChain = make_shared< SwapChain>();
	_rootsig = make_shared<RootSig>();
	_cb = make_shared<ConstantBuffer>();

	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(window,_device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootsig->Init(_device->GetDevice());
	_cb->Init(sizeof(Transform),256);
}
void Engine::Render()
{
	RenderBegin();
	RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_window.width = width;
	_window.height = height;
	RECT rect = { 0, 0, width, height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	//윈도우 크기를 조절
	::SetWindowPos(_window.hwnd, 0, 100, 100, width, height, 0);
	//원하는 위치에 윈도우를 세팅해주는 역활

}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport,&_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}
