#pragma once

#include "Core/CoreMinimal.h"

struct FMAccountInfo
{
	int32 uniqueId = 0;
	
	FString name;	// ´Ð³×ÀÓ
	
	FMAccountInfo() { }

	FMAccountInfo(const int32 _uniqueId) : uniqueId(_uniqueId) { }

	FMAccountInfo(const int32 _uniqueId, const  string _name) : uniqueId(_uniqueId), name(_name){ }
};