#include "AGameMode.h"

#include "Core/MLog.h"

AGameMode::AGameMode()
{

}

AGameMode::~AGameMode()
{

}

void AGameMode::StartPlay()
{
	M_LOG("============ 게임 시작 ============");
}

void AGameMode::EndPlay()
{
	M_LOG("============ 게임   끝 ============");
}
