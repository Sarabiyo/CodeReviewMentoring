#pragma once

#include "Core/CoreMinimal.h"

UCLASS()
class UUserWidget
{
	GENERATED_BODY()

public:
	UUserWidget();
	virtual ~UUserWidget();

	virtual void NativeConstruct();
	virtual void NativeDestruct();
};
