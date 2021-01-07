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

	/** ���� ���� �õ� */
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

	M_LOG("Net ���� �õ�");

	FMNetSessionCallback ackNetConnectCallback = bind(&FMWorldController::ackNetConnect, this);
	NetSession->Connect(ackNetConnectCallback);
}

void FMWorldController::ackNetConnect()
{
	M_LOG("Net ���� ����");

	reqAccountInfos();
}

void FMWorldController::reqAccountInfos()
{
	if (NetSession == nullptr)
		return;

	M_LOG("Request - ���� ���� ����Ʈ");

	FMNetSessionCallback ackAccountInfosCallback = bind(&FMWorldController::ackAccountInfos, this);
	NetSession->RequestPacket(ackAccountInfosCallback);
}

void FMWorldController::ackAccountInfos()
{
	M_LOG("Ack - ���� ���� ����Ʈ");

	shared_ptr<IMWorldModel> worldModelSp = FMMvcHolder::Get().GetWorldModel();
	if (worldModelSp == nullptr)
		return;

	/** ���� ������ (�����ͼ� �̱���) */
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
	
	/** View�� ��Ƽ */
	shared_ptr<IMWorldView> worldViewSp = FMMvcHolder::Get().GetWorldView();
	if (worldViewSp == nullptr)
		return;

	worldViewSp->AckAccountInfos();
}
