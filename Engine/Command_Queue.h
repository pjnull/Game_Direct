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
	//�ٽ��ڵ�
	ComPtr<ID3D12CommandQueue> _cmdQueue;
	ComPtr<ID3D12CommandAllocator> _cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList> _cmdList;
	
	ComPtr<ID3D12CommandAllocator> _resCmdAlloc;
	ComPtr<ID3D12GraphicsCommandList> _resCmdList;

	//Queue=�ϰ��� �־��� 
	//Alloc=�Ҵ����ֱ� ���� �޸� ����
	//List=�ϰ� ����Ʈ
	

	//Fence->Cpu/Gpu����ȭ�� ���� ����
	//�߰� ����� ��ٷ��߸� �ϴ� ��Ȳ�� ���Ѱ�
	ComPtr<ID3D12Fence>				_fence;
	uint32							_fenceValue = 0;
	HANDLE							_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>			_swapChain;
};

