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
	/** 바로 성공*/

	OnNetConnectSuccess();
}
