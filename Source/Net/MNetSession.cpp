#include "MNetSession.h"

FMNetSession::FMNetSession()
{
}

FMNetSession::~FMNetSession()
{
}

void FMNetSession::Connect(const FMNetSessionCallback& onNetConnectSuccess)
{
	OnNetConnectSuccess = onNetConnectSuccess;

	connect();
}

void FMNetSession::connect()
{
	/** �ٷ� ����*/

	OnNetConnectSuccess();
}
