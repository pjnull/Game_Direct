#include "pch.h"
#include "Engine.h"



void Engine::Init(const WindowInfo& window)
{
	_window = window;
	_viewport = { 0,0,static_cast<FLOAT>(window.width),static_cast<FLOAT>(window.height),0.0f,1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, window.width, window.height);
	
	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(window,_device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootsig->Init();
	_cb->Init(sizeof(Transform),256);
	_tableDescHeap->Init(256);
	_depthStencilBuffer->Init(_window);

	_input->Init(window.hwnd);
	_timer->Init();

	ResizeWindow(window.width, window.height);
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
	_depthStencilBuffer->Init(_window);

}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport,&_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::Update()
{
	_input->Update();
	_timer->Update();
	ShowFps();
}

void Engine::ShowFps()
{
	uint32 fps = _timer->GetFps();
	WCHAR text[100] = L"";
	::wsprintf(text, L"FPS:%d", fps);
	::SetWindowText(_window.hwnd, text);
}
