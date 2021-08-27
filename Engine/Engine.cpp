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

void Engine::ResizeWindow(int32 width, int height)
{
	_window.width = width;
	_window.height = height;
	RECT rect = {0, 0, width, height};
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_window.hwnd, 0, 100, 100, width, height,0);

}
