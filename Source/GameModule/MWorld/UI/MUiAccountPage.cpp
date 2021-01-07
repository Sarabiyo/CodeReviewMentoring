#include "MUiAccountPage.h"

#include "Core/MLog.h"

#include "Holder/MMvcHolder.h"

#include "GameModule/MWorld/MWorldDef.h"
#include "GameModule/MWorld/Interface/IMWorldModel.h"

#include "Slates/Components/TextBlock.h"
#include "Slates/Util/WidgetUtil.h"

UMUiAccountPage::UMUiAccountPage()
{
	IdText = FWidgetUtil::CreateWidget<UTextBlock>();
	NameText = FWidgetUtil::CreateWidget<UTextBlock>();
}

UMUiAccountPage::~UMUiAccountPage()
{
	if (IdText)
		delete IdText;
	if (NameText)
		delete NameText;
}

void UMUiAccountPage::NativeConstruct()
{
	UMUiMainPanel::NativeConstruct();
	
	M_LOG("AccountPage ¿ÀÇÂ");

	updateMyAccountInfo();
}

void UMUiAccountPage::NativeDestruct()
{
	UMUiMainPanel::NativeDestruct();

	M_LOG("AccountPage Á¦°Å");
}

void UMUiAccountPage::Back()
{
	UMUiMainPanel::Back();
}

void UMUiAccountPage::Close()
{
	UMUiMainPanel::Close();
}

void UMUiAccountPage::updateMyAccountInfo()
{
	shared_ptr<IMWorldModel> worldModelSp = FMMvcHolder::Get().GetWorldModel();
	if (worldModelSp == nullptr)
	{
		M_LOG("WorldModel is nullptr");
		return;
	}
	
	shared_ptr<FMAccountInfo> accountInfo = worldModelSp->GetMyAccountInfo();
	if (accountInfo == nullptr)
	{
		M_LOG("MyAccountInfo is nullptr");
		return;
	}

	setIdText(accountInfo->uniqueId);
	setNameText(accountInfo->name);
}

void UMUiAccountPage::setNameText(const FString name)
{
	if (NameText)
	{
		NameText->SetText(name);
	}
}

void UMUiAccountPage::setIdText(const int32 uniqueid)
{
	if (IdText)
	{
		IdText->SetText(to_string(uniqueid));
	}
}
