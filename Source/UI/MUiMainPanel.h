#pragma once

#include "Core/CoreMinimal.h"
#include "Slates/Components/UserWidget.h"

UCLASS()
class UMUiMainPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UMUiMainPanel();
	virtual ~UMUiMainPanel();


	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
};

