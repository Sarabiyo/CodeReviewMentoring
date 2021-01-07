#include "MMvcHolder.h"

#include "GameModule/MWorld/MVC/MWorldModel.h"
#include "GameModule/MWorld/MVC/MWorldView.h"
#include "GameModule/MWorld/MVC/MWorldController.h"

shared_ptr<FMMvcHolder> FMMvcHolder::MvcHolder = nullptr;

FMMvcHolder& FMMvcHolder::Get()
{
	if (MvcHolder == nullptr)
	{
		MvcHolder = make_shared<FMMvcHolder>();
	}
	return *MvcHolder;
}

void FMMvcHolder::ReleaseGameModules()
{
	MvcHolder->Reset();
	MvcHolder.reset();
}

void FMMvcHolder::InitWorldMVC()
{
	setWorldModel(make_shared<FMWorldModel>());
	setWorldView(make_shared<FMWorldView>());
	setWorldController(make_shared<FMWorldController>());
}

void FMMvcHolder::Reset()
{
	/** MVC Instance «ÿ¡¶*/
	WorldModelSp.reset();
	WorldViewSp.reset();
	WorldControllerSp.reset();
}
