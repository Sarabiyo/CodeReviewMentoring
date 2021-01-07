#include "MWorldController.h"

#include "Core/MLog.h"

#include "Net/MNetSession.h"

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
	if (NetSession)
	{
		NetSession->IsConnecting();
	}
	return false;
}

void FMWorldController::reqNetConnect()
{
	M_LOG("Net ���� �õ�");

	FMNetSessionCallback ackNetConnectCallback = bind(&FMWorldController::ackNetConnect, this);
	NetSession->Connect(ackNetConnectCallback);
}

void FMWorldController::ackNetConnect()
{
	M_LOG("Net ���� ����");
}
