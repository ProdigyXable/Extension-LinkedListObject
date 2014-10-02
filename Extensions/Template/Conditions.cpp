
#include "Common.h"

bool Extension::emptyList()
{
	return FusionLList.headNode->NextNode->sentinel;

}

bool Extension::NodeInsertion()
{
	return true;
}

bool Extension::NodeRemoval()
{
	return true;
}

bool Extension::ListClear()
{
	return true;
}

bool Extension::IndexBounds()
{
	return true;
}