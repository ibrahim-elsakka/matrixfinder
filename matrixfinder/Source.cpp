#include "mem.h"
#include <iostream>
#include "offsets.h"
#include <string>

int main()
{
	RPM rpm;
	rpm.attach("STAR WARS BATTLEFRONT II");
	for(;;)
	{
		GAMERENDERER pGAMERENDERER = rpm.read<GAMERENDERER>(OFFSET_GAMERENDERER);
		GameRenderer pGameRenderer = rpm.read<GameRenderer>(pGAMERENDERER.gameRenderer);
		RenderView pRenderVew = rpm.read<RenderView>(pGameRenderer.renderView);
		
		system("CLS");
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				std::cout << std::to_string(pRenderVew.viewProj(r, c)).substr(0, 8) << "\t";
			}
			std::cout << std::endl;
		}
		Sleep(100);
	}
}
