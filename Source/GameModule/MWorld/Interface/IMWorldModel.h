#pragma once

struct FMAccountInfo;

class IMWorldModel
{
public:
	IMWorldModel() {}
	virtual ~IMWorldModel() {}

	virtual void Init() = 0;

	/** 계정 정보 */
	virtual void UpdateAccountInfo(const FMAccountInfo& accountInfo) = 0;

	virtual shared_ptr<FMAccountInfo> FindAccountInfo(const int32 uniqueId) { return nullptr; }

	virtual void SetMyAccountId(const int32 uniqueId) = 0;

	virtual shared_ptr<FMAccountInfo> GetMyAccountInfo() { return nullptr; }
	//
};

