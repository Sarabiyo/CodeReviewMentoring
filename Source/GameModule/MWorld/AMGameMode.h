#pragma once

#include "GameModule/AGameMode.h"

UCLASS()
class AMGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	/** AGameModule Functions */
	virtual void BeginPlay() override;
	virtual void EndPlay() override;
	//

};

