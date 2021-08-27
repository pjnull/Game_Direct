#pragma once

class SwapChain;
class DescriptorHeap;


class Command_Queue
{
public:
	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain, shared_ptr<DescriptorHeap> descHeap);
	void WaitSync();
	~Command_Queue();
private:
	ComPtr<ID3D12CommandQueue> _cmdQueue;
	ComPtr<ID3D12CommandAllocator> _cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList> _cmdList;
	ComPtr<ID3D12Fence>				_fence;
	UINT32							_fenceValue = 0;
	HANDLE							_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>			_swapChain;
	shared_ptr<DescriptorHeap>		_descHeap;
};

