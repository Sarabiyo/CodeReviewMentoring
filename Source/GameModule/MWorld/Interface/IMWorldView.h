#pragma once

class IMWorldView
{
public:
	IMWorldView() {}
	virtual ~IMWorldView() {}

	virtual void Init() = 0;

	/** 계정 정보 리스트 */
	virtual void AckAccountInfos() = 0;
};

