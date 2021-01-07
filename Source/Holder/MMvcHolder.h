#pragma once

#include "Core/CoreMinimal.h"

class IMWorldModel;
class IMWorldView;
class IMWorldController;

class MMvcHolder
{
public:
	static MMvcHolder& Get();

	/** ½Ì±ÛÅæ ÀÎ½ºÅÏ½º ÆÄ±« */
	static void Destroy();

	/** ¸®¼Â */
	void Reset();

	/** World MVC Set */
	void SetWorldModel(shared_ptr<IMWorldModel> worldModel) { WorldModelSp.swap(worldModel);}
	shared_ptr<IMWorldModel> GetWorldModel() { return WorldModelSp; }

	void SetWorldView(shared_ptr<IMWorldView> worldView) { WorldViewSp.swap(worldView); }
	shared_ptr<IMWorldView> GetWorldView() { return WorldViewSp; }

	void SetWorldController(shared_ptr<IMWorldController> worldcontroller) { WorldControllerSp.swap(worldcontroller); }
	shared_ptr<IMWorldController> GetWorldController() { return WorldControllerSp; }
	//

private:
	static shared_ptr<MMvcHolder> MvcHolder;

	/** World MVC Interface */
	shared_ptr<IMWorldModel> WorldModelSp;
	shared_ptr<IMWorldView> WorldViewSp;
	shared_ptr<IMWorldController> WorldControllerSp;
};

