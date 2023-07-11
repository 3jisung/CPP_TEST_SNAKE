#pragma once
#include "ConsoleObject.h"
#include <list>

// Ό³Έν :
class ConsoleEngineCore
{
public:
	// constrcuter destructer
	ConsoleEngineCore();
	~ConsoleEngineCore();

	// delete Function
	ConsoleEngineCore(const ConsoleEngineCore& _Other) = delete;
	ConsoleEngineCore(ConsoleEngineCore&& _Other) noexcept = delete;
	ConsoleEngineCore& operator=(const ConsoleEngineCore& _Other) = delete;
	ConsoleEngineCore& operator=(ConsoleEngineCore&& _Other) noexcept = delete;

	static void EngineOff()
	{
		IsEngineProcess = false;
	}

	static void EngineStart(const int4& Scale);

	template<typename ObjectType>
	static ObjectType* CreateObject()
	{
		ObjectType* NewObject = new ObjectType();
		Objects.push_back(NewObject);
		return NewObject;
	}

	static ConsoleScreen Screen;

	template<typename ObjectType>
	static void pushBackObject(ObjectType NewObject)
	{
		Objects.push_back(NewObject);
	}

	static std::list<ConsoleObject*>::iterator Begin()
	{
		return Objects.begin();
	}

	static std::list<ConsoleObject*>::iterator End()
	{
		return Objects.end();
	}

	static void Erase(std::list<ConsoleObject*>::iterator& object)
	{
		Objects.erase(object);
	}

	static void AllRelease();

protected:

private:
	static std::list<ConsoleObject*> Objects;
	static bool IsEngineProcess;
};