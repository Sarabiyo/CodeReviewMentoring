#pragma once

#include "Core/MLog.h"

class FWidgetUtil
{
public:
	template<typename T>
	static T* CreateWidget()
	{
		T* newWidget = new T();
		if (newWidget == nullptr)
			M_LOG("CreateWidget ½ÇÆÐ");
		return newWidget;
	}
};