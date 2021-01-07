#pragma once

#include "Core/CoreMinimal.h"

struct FMAccountInfo
{
	int32 uniqueId = 0;
	
	FString name;	// ´Ð³×ÀÓ
	
	FMAccountInfo() { }

	FMAccountInfo(int32 _uniqueId) : uniqueId(_uniqueId) { }
};