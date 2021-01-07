#include "UserWidget.h"

#include "Core/MLog.h"

UUserWidget::UUserWidget()
{
}

UUserWidget::~UUserWidget()
{
}

void UUserWidget::NativeConstruct()
{
}

void UUserWidget::NativeDestruct()
{
}

void UUserWidget::AddToViewPort(const int32 zOrder)
{
	M_LOG("À§Á¬ Ãß°¡ [Z : %d]", zOrder);

	NativeConstruct();
}

void UUserWidget::RemoveFromParent()
{
	M_LOG("À§Á¬ Á¦°Å");

	NativeDestruct();
}
