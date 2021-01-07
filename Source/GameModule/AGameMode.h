#pragma once

#include "Core/CoreMinimal.h"

UCLASS()
class AGameMode
{
	GENERATED_BODY()

public:
	AGameMode();
	virtual ~AGameMode();

	virtual void StartPlay();
	virtual void EndPlay();
};

