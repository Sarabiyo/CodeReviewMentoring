#pragma once

#include "Core/CoreMinimal.h"

#include "GameModule/MWorld/Interface/IMWorldController.h"

class FMNetSession;

class FMWorldController : public IMWorldController
{
public:
	FMWorldController();
	virtual ~FMWorldController();

	virtual void Init() override;

	virtual bool IsNetConnecting() override;

private:
	void reqNetConnect();

	void ackNetConnect();

private:
	shared_ptr<FMNetSession> NetSession;
};
