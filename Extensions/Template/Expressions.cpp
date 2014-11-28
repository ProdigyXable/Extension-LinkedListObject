
#include "Common.h"

int Extension::getEndData()
{
	return FusionLList.tailNode->PrevNode->getIntData();
}
int Extension::getStartData()
{
	return FusionLList.headNode->NextNode->getIntData();
}
int Extension::getData(int index)
{
	if(index == 0)
	{
		return Extension::getStartData();
	}

	else if(index == LinkedList::ListSize)
	{
		return Extension::getEndData();
	}

	else if(index < 0 || index >= LinkedList::ListSize)
	{
		Runtime.GenerateEvent(IndexError);
		return -1;
	}

	else
	{
		return FusionLList.findNode(index)->getIntData();
	}
}


int Extension::ListSize()
{
	return FusionLList.ListSize;
}
