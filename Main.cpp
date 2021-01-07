#include "GameModule/MWorld/AMGameMode.h"

int main()
{
	AGameMode* gameMode = new AMGameMode();
	if (gameMode)
	{
		gameMode->StartPlay();

		gameMode->EndPlay();
		
		delete gameMode;
	}
	return 0;
}