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
	virtual void UpdateAccountInfo(const FMAccountInfo& accountInfo);

	virtual shared_ptr<FMAccountInfo> FindAccountInfo(int32 uniqueId);

	virtual shared_ptr<FMAccountInfo> GetMyAccountInfo();
};

