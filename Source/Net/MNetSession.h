#pragma once

#include "Core/CoreMinimal.h"

using FMNetSessionCallback = function<void()>;

class FMNetSession
{
public:
	FMNetSession();
	virtual ~FMNetSession();

	/** Net ¿¬°á */
	void Connect(const FMNetSessionCallback& onNetConnectSuccess);

	bool IsConnecting() const { return bIsConnecting; }

private:
	void connect();

private:
	FMNetSessionCallback OnNetConnectSuccess;

	bool bIsConnecting = false;
};

