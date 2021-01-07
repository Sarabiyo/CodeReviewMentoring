#pragma once

#include "Core/CoreMinimal.h"

using FMNetSessionCallback = function<void()>;

class FMNetSession
{
public:
	FMNetSession();
	virtual ~FMNetSession();

	/** Net 연결 */
	void Connect(const FMNetSessionCallback& onNetConnectSuccess);

	bool IsConnecting() const { return bIsConnecting; }

	/**
	 *	서버 패킷 요청
	 *  데이터 미구현
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

