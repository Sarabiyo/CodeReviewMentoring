#pragma once

#include "GameModule/MWorld/Interface/IMWorldView.h"

class FMWorldView : public IMWorldView
{
public:
	FMWorldView();
	virtual ~FMWorldView();

	virtual void Init() override;

	/** ���� ���� ����Ʈ */
	virtual void AckAccountInfos() override;

	/** ���� ���� ������ */
	void OpenAccountPage();
};

