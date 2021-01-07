#pragma once

#include "Core/CoreMinimal.h"

using FMNetSessionCallback = function<void()>;

class FMNetSession
{
public:
	FMNetSession();
	virtual ~FMNetSession();

	/** Net ���� */
	void Connect(const FMNetSessionCallback& onNetConnectSuccess);

	bool IsConnecting() const { return bIsConnecting; }

	/**
	 *	���� ��Ŷ ��û
	 *  ������ �̱���
	 */

	void RequestPacket(const FMNetSessionCallback ackNetPacketCallback);

private:
	void connect();
	
	void ackNetPacket();

private:
	FMNetSessionCallback OnNetConnectSuccess;

	FMNetSessionCallback AckNetPacketCallback;

	bool bIsConnecting = false;
};

