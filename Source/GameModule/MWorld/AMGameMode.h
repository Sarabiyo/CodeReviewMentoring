#pragma once

#include "GameModule/AGameMode.h"

UCLASS()
class AMGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	/** AGameModule Intefaces */
	virtual void StartPlay() override;
	virtual void EndPlay() override;
	//
};