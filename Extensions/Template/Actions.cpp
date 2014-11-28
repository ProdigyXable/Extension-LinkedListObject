
#include "Common.h"


void Extension::addEndNode(int value)
{
	FusionLList.addEnd(value);
	Runtime.GenerateEvent(NewNode);
}

void Extension::addFrontNode(int value)
{
	FusionLList.addFront(value);
	Runtime.GenerateEvent(NewNode);
}

void Extension::addAnyNode(int index, int value)
{
	if(index == 0)
	{
		FusionLList.addFront(value);
		Runtime.GenerateEvent(NewNode);
	}

	else if(index == LinkedList::ListSize)
	{
		FusionLList.addEnd(value);
		Runtime.GenerateEvent(NewNode);
	}

	else if(index < 0 || index >= LinkedList::ListSize)
	{
		Runtime.GenerateEvent(IndexError);
	}

	else
	{
		Node * newNode = new Node(value);
		Node * buffer = FusionLList.findNode(index - 1);

		newNode->PrevNode = buffer;
		newNode->NextNode = buffer->NextNode;

		buffer->NextNode = buffer->NextNode->PrevNode = newNode;
		
		LinkedList::ListSize++;
		Runtime.GenerateEvent(NewNode);
	}
}

void Extension::removeFrontNode()
{
	FusionLList.removeFront();
	Runtime.GenerateEvent(RemovedNode);
}

void Extension::removeEndNode()
{
	FusionLList.removeEnd();
	Runtime.GenerateEvent(RemovedNode);
}

void Extension::removeAnyNode(int index)
{
	if(index == 0)
	{
		Extension::removeFrontNode();
		Runtime.GenerateEvent(RemovedNode);
	}

	else if( (index) == LinkedList::ListSize)
	{
		FusionLList.removeEnd();
		Runtime.GenerateEvent(RemovedNode);
	}

	else if(index < 0 || index >= LinkedList::ListSize)
	{
		Runtime.GenerateEvent(IndexError);
	}

	else
	{
		Node * buffer = FusionLList.findNode(index);

		buffer->PrevNode->NextNode = buffer->NextNode;
		buffer->NextNode->PrevNode = buffer->PrevNode;
		
		delete buffer;
		LinkedList::ListSize--;
		Runtime.GenerateEvent(RemovedNode);
	}
}

void Extension::erase(int index, int amount)
{
	Node * buffer = FusionLList.findNode(index);

	for(int i = 0; i < amount; i++)
	{
		removeAnyNode(index);
		Runtime.GenerateEvent(RemovedNode);
		Runtime.GenerateEvent(ListCleared);
	}
}

void Extension::swap(int indexA, int indexB)
{
	if(!(indexA < 0 || indexA > LinkedList::ListSize - 1 || indexB < 0 || indexB > LinkedList::ListSize - 1))
	{
		Node * a = FusionLList.findNode(min(indexA,indexB));
		Node * b = FusionLList.findNode(max(indexA,indexB));

		if((FusionLList.headNode->NextNode->sentinel == false) && !(a->NextNode == b || a->PrevNode == b) )
		{
			a->PrevNode->NextNode = b;
			b->PrevNode->NextNode = a;
	
			a->NextNode->PrevNode = b;
			b->NextNode->PrevNode = a;

			std::swap(a->NextNode, b->NextNode);
			std::swap(a->PrevNode, b->PrevNode);

			/*
			// Content Copying
			int buffer = a->getIntData();
			a->setData(b->getIntData());
			b->setData(buffer);
			*/
		}

		else if(a->NextNode == b || a->PrevNode == b)
		{
			a->PrevNode->NextNode = b;
			b->NextNode->PrevNode = a;

			b->PrevNode = a->PrevNode;
			a->NextNode = b->NextNode;
			b->NextNode = a;
			a->PrevNode = b;
		}
	}

	else
	{
		Runtime.GenerateEvent(IndexError);
	}
	

}

void Extension::reverse()
{
	for(int i = 0; i < (LinkedList::ListSize + 1 )/2; i++)
	{
		swap(i, (LinkedList::ListSize - (i + 1)));
	}
}
void Extension::reverseSection(int indexA, int indexB)
{
	
	int temp = max(indexA,indexB);
	
	indexA = max(0, min(indexA,indexB));
	indexB = min(temp, LinkedList::ListSize - 1);
		
	for(int i = 0; i < (indexB - indexA + 1)/2; i++)
	{
		swap(indexA + i, (indexB - i));
	}
}