
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

	else if(index == Extension::LinkedList::ListSize)
	{
		FusionLList.addEnd(value);
		Runtime.GenerateEvent(NewNode);
	}

	else if(index < 0 || index >= Extension::LinkedList::ListSize)
	{
		// Error: Out of bounds index
	}

	else
	{
		Node * newNode = new Node(value);
		Node * buffer = FusionLList.findNode(index);

		newNode->PrevNode = buffer;
		newNode->NextNode = buffer->NextNode;

		buffer->NextNode = buffer->NextNode->PrevNode = newNode;
		
		Extension::LinkedList::ListSize++;
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
		// Error: Out of Index
	}

	else
	{
		Node * buffer = FusionLList.findNode(index);

		buffer->PrevNode->NextNode = buffer->NextNode;
		buffer->NextNode->PrevNode = buffer->PrevNode;
		
		delete buffer;
		Extension::LinkedList::ListSize--;
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
	Node * a = FusionLList.findNode(indexA);
	Node * b = FusionLList.findNode(indexB);


	// Content Copying
	int buffer = a->getIntData();
	a->setData(b->getIntData());
	b->setData(buffer);

}

void Extension::reverse()
{
	for(int i = 0; i < (Extension::LinkedList::ListSize + 1 )/2; i++)
	{
		swap(i, (Extension::LinkedList::ListSize - (i + 1)));
	}
}
void Extension::reverseSection(int indexA, int indexB)
{
	
	int temp = max(indexA,indexB);
	
	indexA = max(0, min(indexA,indexB));
	indexB = min(temp, Extension::LinkedList::ListSize - 1);
		
	for(int i = 0; i < (indexB - indexA + 1)/2; i++)
	{
		swap(indexA + i, (indexB - i));
	}
}