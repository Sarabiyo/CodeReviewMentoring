#include "MMvcHolder.h"

shared_ptr<MMvcHolder> MMvcHolder::MvcHolder = nullptr;

MMvcHolder& MMvcHolder::Get()
{
	if (MvcHolder == nullptr)
	{
		MvcHolder = make_shared<MMvcHolder>();
	}
	return *MvcHolder;
}

void MMvcHolder::Destroy()
{
	MvcHolder.reset();
}

void MMvcHolder::Reset()
{
	/** MVC Instance «ÿ¡¶*/
	WorldModelSp.reset();
	WorldViewSp.reset();
	WorldControllerSp.reset();
}
