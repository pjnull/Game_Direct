#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "Command_Queue.h"
#include "SwapChain.h"
#include "Descriptor_Heap.h"



void Engine::Init(const WindowInfo& window)
{
	_window = window;
	ResizeWindow(window.width, window.height);
	_viewport = { 0,0,static_cast<FLOAT>(window.width),static_cast<FLOAT>(window.height),0.0f,1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, window.width, window.height);
	_cmdQueue = make_shared< CommandQueue>();
	_device = make_shared< Device>();
	_swapChain = make_shared< SwapChain>();
	_descHeap = make_shared< DescriptorHeap>();

	_device->Init();


}
void Engine::Render()
{
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
