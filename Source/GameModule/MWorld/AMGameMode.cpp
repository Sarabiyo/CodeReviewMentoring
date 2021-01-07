#include "AMGameMode.h"

#include "Holder/MMvcHolder.h"

#include "GameModule/MWorld/Interface/IMWorldModel.h"
#include "GameModule/MWorld/Interface/IMWorldView.h"
#include "GameModule/MWorld/Interface/IMWorldController.h"

void AMGameMode::StartPlay()
{
	AGameMode::StartPlay();

	FMMvcHolder& mvcHolder = FMMvcHolder::Get();
	/** 월드 MVC 생성*/
	mvcHolder.InitWorldMVC();

	shared_ptr<IMWorldController> worldControllerSp = mvcHolder.GetWorldController();
	if (worldControllerSp)
	{
		worldControllerSp->Init();
	}

	shared_ptr<IMWorldView> worldViewSp = mvcHolder.GetWorldView();
	if (worldViewSp)
	{
		worldViewSp->Init();
	}


}

void AMGameMode::EndPlay()
{
	AGameMode::EndPlay();
}
