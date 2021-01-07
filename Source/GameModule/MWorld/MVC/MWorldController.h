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
	/** 서버 연결 */
	void reqNetConnect();
	void ackNetConnect();
	//

	/** 계정 정보 리스트 */
	void reqAccountInfos();
	void ackAccountInfos();
	//

private:
	shared_ptr<FMNetSession> NetSession;
};
