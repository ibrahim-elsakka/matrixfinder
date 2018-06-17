#include <Windows.h>
#include <d3dx9math.h>
#pragma comment(lib, "d3dx9.lib")

// Created with ReClass.NET by KN4CK3R

#define OFFSET_GAMERENDERER 0x144523de0

// Created with ReClass.NET by KN4CK3R

class RenderView
{
public:
	D3DXMATRIXA16 m_Transform1; //0x0000
	D3DXMATRIXA16 m_Transform2; //0x0040
	char pad_0080[944]; //0x0080
	D3DXMATRIXA16 viewProj; //0x0430
	char pad_0470[640]; //0x0470
}; //Size: 0x06F0

class GameRenderer
{
public:
	char pad_0000[1336]; //0x0000
	DWORD_PTR renderView; //0x0538
	char pad_0540[8]; //0x0540
}; //Size: 0x0548

class GAMERENDERER
{
public:
	DWORD_PTR gameRenderer; //0x0000
	char pad_0008[56]; //0x0008
}; //Size: 0x0040

