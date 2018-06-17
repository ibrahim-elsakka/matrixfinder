#include "mem.h"
#include <iostream>
#include "offsets.h"
#include <string>
D3DXMATRIXA16 lastMatrix;
int main()
{
	RPM rpm;
	rpm.attach("STAR WARS BATTLEFRONT II");
	for(;;)
	{
		GAMERENDERER pGAMERENDERER = rpm.read<GAMERENDERER>(OFFSET_GAMERENDERER);
		GameRenderer pGameRenderer = rpm.read<GameRenderer>(pGAMERENDERER.gameRenderer);
		RenderView pRenderVew = rpm.read<RenderView>(pGameRenderer.renderView);
		D3DXMATRIXA16 thisMatrix = pRenderVew.m_Transform1;
		if (lastMatrix != thisMatrix) {
			lastMatrix = thisMatrix;
			system("CLS");
			for (int r = 0; r < 4; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					std::cout << std::to_string(thisMatrix(r, c)).substr(0, 8) << "\t";
				}
				std::cout << std::endl;
			}
		}
		Sleep(20);
	}
}
