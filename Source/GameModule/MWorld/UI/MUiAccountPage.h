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

	/** �� ���� ���� �� */
	void updateMyAccountInfo();

private:
	/** ���� ���̵� */
	void setIdText(const int32 uniqueid);

	/** �г��� */
	void setNameText(const FString name);

protected:
	/** ���� ���̵� */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* IdText = nullptr;

	/** �г��� */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NameText = nullptr;
};

