#pragma once

class IMWorldView
{
public:
	IMWorldView() {}
	virtual ~IMWorldView() {}

	virtual void Init() = 0;

	/** ���� ���� ����Ʈ */
	virtual void AckAccountInfos() = 0;
};

