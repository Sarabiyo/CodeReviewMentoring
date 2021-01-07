#include "MNetSession.h"

#include "Core/MLog.h"

FMNetSession::FMNetSession()
{
}

FMNetSession::~FMNetSession()
{
}

void FMNetSession::Connect(const FMNetSessionCallback& onNetConnectSuccess)
{
	M_LOG("서버 연결 시도");

	OnNetConnectSuccess = onNetConnectSuccess;

	connect();
}

void FMNetSession::RequestPacket(const FMNetSessionCallback ackNetPacketCallback)
{
	M_LOG("패킷 Request");

	AckNetPacketCallback = ackNetPacketCallback;

	ackNetPacket();
}

void FMNetSession::connect()
{
	/** 바로 성공*/

	M_LOG("서버 연결 성공");
	OnNetConnectSuccess();
}

void FMNetSession::ackNetPacket()
{
	M_LOG("패킷 Ack");

	AckNetPacketCallback();
}
