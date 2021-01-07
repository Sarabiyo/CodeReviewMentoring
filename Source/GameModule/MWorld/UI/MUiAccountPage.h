#pragma once

#include "Core/CoreMinimal.h"
#include "UI/MUiMainPanel.h"

class UTextBlock;

UCLASS()
class UMUiAccountPage : public UMUiMainPanel
{
	GENERATED_BODY()

public:
	UMUiAccountPage();
	virtual ~UMUiAccountPage();

	/** UUserWidget Interfaces */
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//

	/** UMUiMainPanel Interfaces */
	virtual void Back() override;
	virtual void Close() override;
	//

	/** 내 계정 정보 셋 */
	void updateMyAccountInfo();

private:
	/** 고유 아이디 */
	void setIdText(const int32 uniqueid);

	/** 닉네임 */
	void setNameText(const FString name);

protected:
	/** 고유 아이디 */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* IdText = nullptr;

	/** 닉네임 */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameText = nullptr;
};

