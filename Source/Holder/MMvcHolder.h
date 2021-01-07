#pragma once

#include "Core/CoreMinimal.h"

class IMWorldModel;
class IMWorldView;
class IMWorldController;

class FMMvcHolder
{
public:
	static FMMvcHolder& Get();

	/** �̱��� �ν��Ͻ� �ı� */
	static void ReleaseGameModules();

	/** ���� �ν��Ͻ� ���� */
	void InitWorldMVC();

	/** ���� */
	void Reset();

	/** World MVC Get */
	shared_ptr<IMWorldModel> GetWorldModel() { return WorldModelSp; }
	shared_ptr<IMWorldView> GetWorldView() { return WorldViewSp; }
	shared_ptr<IMWorldController> GetWorldController() { return WorldControllerSp; }
	//
private:
	/** World MVC set */
	void setWorldModel(shared_ptr<IMWorldModel> worldModel) { WorldModelSp.swap(worldModel); }
	void setWorldView(shared_ptr<IMWorldView> worldView) { WorldViewSp.swap(worldView); }
	void setWorldController(shared_ptr<IMWorldController> worldcontroller) { WorldControllerSp.swap(worldcontroller); }
	//

private:
	static shared_ptr<FMMvcHolder> MvcHolder;

	/** World MVC Interface */
	shared_ptr<IMWorldModel> WorldModelSp;
	shared_ptr<IMWorldView> WorldViewSp;
	shared_ptr<IMWorldController> WorldControllerSp;
};

