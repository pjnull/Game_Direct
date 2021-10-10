#pragma once

class SwapChain;
class Descriptor_Heap;


class Command_Queue
{
public:
	~Command_Queue();
	  
	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain);
	void WaitSync();
	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();
	void FlushResourceCommandQueue();

	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return _cmdQueue; }
	ComPtr<ID3D12GraphicsCommandList> GetCmdlist() { return _cmdList; }
	ComPtr<ID3D12GraphicsCommandList> GetResCmdlist() { return _resCmdList; }
private:
	//핵심코드
	ComPtr<ID3D12CommandQueue> _cmdQueue;
	ComPtr<ID3D12CommandAllocator> _cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList> _cmdList;
	
	ComPtr<ID3D12CommandAllocator> _resCmdAlloc;
	ComPtr<ID3D12GraphicsCommandList> _resCmdList;

	//Queue=일감을 넣어줌 
	//Alloc=할당해주기 위한 메모리 공간
	//List=일감 리스트
	

	//Fence->Cpu/Gpu동기화를 위한 도구
	//중간 결과를 기다려야만 하는 상황을 위한것
	ComPtr<ID3D12Fence>				_fence;
	uint32							_fenceValue = 0;
	HANDLE							_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>			_swapChain;
};

