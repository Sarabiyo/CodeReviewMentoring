#include "MWorldView.h"

#include "Core/MLog.h"

#include "Slates/Util/WidgetUtil.h"

#include "GameModule/MWorld/UI/MUiAccountPage.h"

//#include "GameModule/MWorld/UI/"

FMWorldView::FMWorldView()
{
}

FMWorldView::~FMWorldView()
{
}

void FMWorldView::Init()
{

}

void FMWorldView::AckAccountInfos()
{
	OpenAccountPage();
}

void FMWorldView::OpenAccountPage()
{
	/** 원랜 허드 통해서*/
	M_LOG("OpenAccountPage");

	UMUiAccountPage* accountPage = FWidgetUtil::CreateWidget<UMUiAccountPage>();
	if (accountPage)
	{
		accountPage->AddToViewPort(1);
	}
}

