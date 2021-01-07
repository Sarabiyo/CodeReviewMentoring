#pragma once

#include "Core/CoreMinimal.h"
#include "Slates/Components/Widget.h"

UCLASS()
class UUserWidget : public UWidget
{
	GENERATED_BODY()

public:
	UUserWidget();
	virtual ~UUserWidget();

	/** UUserWidget Interfaces */
	virtual void NativeConstruct();
	virtual void NativeDestruct();

	virtual void AddToViewPort(const int32 zOrder);
	virtual void RemoveFromParent();
	//
};

