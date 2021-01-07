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
	/** ���� ��� ���ؼ�*/
	M_LOG("OpenAccountPage");

	UMUiAccountPage* accountPage = FWidgetUtil::CreateWidget<UMUiAccountPage>();
	if (accountPage)
	{
		accountPage->AddToViewPort(1);
	}
}

