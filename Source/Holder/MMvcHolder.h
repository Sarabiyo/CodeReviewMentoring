#pragma once

#include "Core/CoreMinimal.h"

class IMWorldModel;
class IMWorldView;
class IMWorldController;

class FMMvcHolder
{
public:
	static FMMvcHolder& Get();

	/** 싱글톤 인스턴스 파괴 */
	static void ReleaseGameModules();

	/** 월드 인스턴스 생성 */
	void InitWorldMVC();

	/** 리셋 */
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

