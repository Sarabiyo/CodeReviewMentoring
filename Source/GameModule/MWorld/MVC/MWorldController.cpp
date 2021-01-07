#include "MWorldController.h"

#include "Core/MLog.h"

#include "Holder/MMvcHolder.h"

#include "Net/MNetSession.h"

#include "GameModule/MWorld/Interface/IMWorldModel.h"
#include "GameModule/MWorld/Interface/IMWorldView.h"
#include "GameModule/MWorld/MWorldDef.h"


FMWorldController::FMWorldController()
{
}

FMWorldController::~FMWorldController()
{
}

void FMWorldController::Init()
{
	if (NetSession == nullptr)
	{
		NetSession = make_shared<FMNetSession>();
	}

	/** 서버 접속 시도 */
	reqNetConnect();
}

bool FMWorldController::IsNetConnecting()
{
	if (NetSession != nullptr)
	{
		NetSession->IsConnecting();
	}
	return false;
}

void FMWorldController::reqNetConnect()
{
	if (NetSession == nullptr)
		return;

	M_LOG("Net 연결 시도");

	FMNetSessionCallback ackNetConnectCallback = bind(&FMWorldController::ackNetConnect, this);
	NetSession->Connect(ackNetConnectCallback);
}

void FMWorldController::ackNetConnect()
{
	M_LOG("Net 연결 성공");

	reqAccountInfos();
}

void FMWorldController::reqAccountInfos()
{
	if (NetSession == nullptr)
		return;

	M_LOG("Request - 계정 정보 리스트");

	FMNetSessionCallback ackAccountInfosCallback = bind(&FMWorldController::ackAccountInfos, this);
	NetSession->RequestPacket(ackAccountInfosCallback);
}

void FMWorldController::ackAccountInfos()
{
	M_LOG("Ack - 계정 정보 리스트");

	shared_ptr<IMWorldModel> worldModelSp = FMMvcHolder::Get().GetWorldModel();
	if (worldModelSp == nullptr)
		return;

	/** 더미 데이터 (데이터셋 미구현) */
	const int32 myAccountId = 2;
	vector<FMAccountInfo> recvAccountInfos =
	{
		{1, "A"}, {2, "B"}, {1, "C"}, {2, "D"}
	};
	
	for (const FMAccountInfo& accountInfo : recvAccountInfos)
	{
		worldModelSp->UpdateAccountInfo(accountInfo);
	}
	
	worldModelSp->SetMyAccountId(myAccountId);
	
	/** View에 노티 */
	shared_ptr<IMWorldView> worldViewSp = FMMvcHolder::Get().GetWorldView();
	if (worldViewSp == nullptr)
		return;

	worldViewSp->AckAccountInfos();
}
