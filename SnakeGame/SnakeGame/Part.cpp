#include "Part.h"

Part::Part()
{
}

Part::~Part()
{
}

void Part::SetNext(Part* next)
{
	this->Next = next;
}

void Part::SetPrev(Part* prev)
{
	this->Prev = prev;
}

void Part::SetPrevPos(int4 prevPos)
{
	this->PrevPos = prevPos;
}

Part* Part::GetNext()
{
	return this->Next;
}

Part* Part::GetPrev()
{
	return this->Prev;
}

int4 Part::GetPrevPos()
{
	return this->PrevPos;
}