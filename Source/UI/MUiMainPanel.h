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

	/** UUserWidget Interfaces */
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//

	/** UMUiMainPanel Interfaces */
	virtual void Back();
	virtual void Close();
	//
};

