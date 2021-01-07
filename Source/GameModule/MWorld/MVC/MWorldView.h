#pragma once

#include "GameModule/MWorld/Interface/IMWorldView.h"

class FMWorldView : public IMWorldView
{
public:
	FMWorldView();
	virtual ~FMWorldView();

	virtual void Init() override;

	/** 계정 정보 리스트 */
	virtual void AckAccountInfos() override;

	/** 계정 정보 페이지 */
	void OpenAccountPage();
};

