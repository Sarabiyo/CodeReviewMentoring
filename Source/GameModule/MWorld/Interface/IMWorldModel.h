#pragma once

struct FMAccountInfo;

class IMWorldModel
{
public:
	IMWorldModel() {}
	virtual ~IMWorldModel() {}

	virtual void UpdateAccountInfo(const FMAccountInfo& accountInfo) = 0;

	virtual shared_ptr<FMAccountInfo> FindAccountInfo(int32 uniqueId) { return nullptr; }

	virtual shared_ptr<FMAccountInfo> GetMyAccountInfo() { return nullptr; }
};

