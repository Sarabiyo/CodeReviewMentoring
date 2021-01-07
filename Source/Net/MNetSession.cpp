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
	M_LOG("���� ���� �õ�");

	OnNetConnectSuccess = onNetConnectSuccess;

	connect();
}

void FMNetSession::RequestPacket(const FMNetSessionCallback ackNetPacketCallback)
{
	M_LOG("��Ŷ Request");

	AckNetPacketCallback = ackNetPacketCallback;

	ackNetPacket();
}

void FMNetSession::connect()
{
	/** �ٷ� ����*/

	M_LOG("���� ���� ����");
	OnNetConnectSuccess();
}

void FMNetSession::ackNetPacket()
{
	M_LOG("��Ŷ Ack");

	AckNetPacketCallback();
}
