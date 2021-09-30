#pragma once


class Device
{
public:
	void Init();
	ComPtr<IDXGIFactory> GetDXGI() {return _dxgi;}
	ComPtr<ID3D12Device> GetDevice() { return _device; }

private:
	ComPtr<ID3D12Debug> _debugController;
	ComPtr<IDXGIFactory> _dxgi;
	ComPtr<ID3D12Device> _device;
};
/*Com(Component Object Model)
 -DX의 프로그래밍 언어 독립성과 하위호환성을 가능하게 하는 기술
 -Com객체를 사용.세부사항은 우리한테 숨겨짐
 -ComPtr==>일종의 스마트 포인터
*/
