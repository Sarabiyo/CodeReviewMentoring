#pragma once

#include "Core/CoreMinimal.h"
#include "Slates/Components/Widget.h"

UCLASS()
class UTextBlock : public UWidget
{
	GENERATED_BODY()

public:
	UTextBlock();
	virtual ~UTextBlock();

	virtual void SetText(const FText& str);
};

