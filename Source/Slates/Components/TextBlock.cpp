#include "TextBlock.h"

#include "Core/MLog.h"

UTextBlock::UTextBlock()
{
}

UTextBlock::~UTextBlock()
{
}

void UTextBlock::SetText(const FText& str)
{
	M_LOG("UTextBlock::SetText(\"%s\")", str.c_str());
}
