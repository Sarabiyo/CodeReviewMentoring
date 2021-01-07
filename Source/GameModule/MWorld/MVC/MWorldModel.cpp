#include "MWorldModel.h"

#include "GameModule/MWorld/MWorldDef.h"

FMWorldModel::FMWorldModel()
{
}

FMWorldModel::~FMWorldModel()
{
}

void FMWorldModel::UpdateAccountInfo(const FMAccountInfo& accountInfo)
{
	const int32 uniqueId = accountInfo.uniqueId;
	if (uniqueId == 0)
		return;

	shared_ptr<FMAccountInfo> accontInfoSp = FindAccountInfo(uniqueId);
	if (accontInfoSp == nullptr)
	{
		AccountInfoMap.emplace(uniqueId, make_shared<FMAccountInfo>(uniqueId));
	}

	accontInfoSp->name = accountInfo.name;
}

shared_ptr<FMAccountInfo> FMWorldModel::FindAccountInfo(int32 uniqueId)
{
	auto it = AccountInfoMap.find(uniqueId);

	if (it != AccountInfoMap.end())
	{
		return it->second;
	}
	return nullptr;
}

shared_ptr<FMAccountInfo> FMWorldModel::GetMyAccountInfo()
{
	return FindAccountInfo(MyAccountId);
}
