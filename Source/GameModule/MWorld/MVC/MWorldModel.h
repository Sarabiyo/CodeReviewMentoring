#pragma once

#include "Core/CoreMinimal.h"
#include "GameModule/MWorld/Interface/IMWorldModel.h"

class FMWorldModel : public IMWorldModel
{
public:
	FMWorldModel();
	virtual ~FMWorldModel();

private:
	map<int32 /** UniqueId */, shared_ptr<FMAccountInfo>> AccountInfoMap;

	int32 MyAccountId = 0;
	
public:
	virtual void Init() override;

	/** 계정 정보 */
	virtual void UpdateAccountInfo(const FMAccountInfo& accountInfo) override;

	virtual shared_ptr<FMAccountInfo> FindAccountInfo(const int32 uniqueId) override;

	virtual void SetMyAccountId(const int32 uniqueId) override;

	virtual shared_ptr<FMAccountInfo> GetMyAccountInfo() override;
	//
};

