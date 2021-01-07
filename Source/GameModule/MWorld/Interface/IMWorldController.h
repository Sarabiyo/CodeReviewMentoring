#pragma once


class IMWorldController
{
public:
	IMWorldController() {}
	virtual ~IMWorldController() {}

	virtual void Init() = 0;

	virtual bool IsNetConnecting() = 0;
};

