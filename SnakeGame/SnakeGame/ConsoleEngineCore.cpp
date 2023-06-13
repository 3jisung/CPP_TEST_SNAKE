#include "ConsoleEngineCore.h"
#include "ConsoleScreen.h"

bool ConsoleEngineCore::IsEngineProcess = true;
std::list<ConsoleObject*> ConsoleEngineCore::Objects;
ConsoleScreen ConsoleEngineCore::Screen;


ConsoleEngineCore::ConsoleEngineCore()
{
}

ConsoleEngineCore::~ConsoleEngineCore()
{
}


void ConsoleEngineCore::EngineStart(const int4& _Scale)
{

	Screen.Init(_Scale, '*');

	while (IsEngineProcess)
	{
		{
			Screen.Clear();

			std::list<ConsoleObject*>::iterator Start = Objects.begin();
			std::list<ConsoleObject*>::iterator End = Objects.end();

			for (; Start != End; ++Start)
			{
				ConsoleObject* Object = (*Start);
				Screen.SetPixel(Object->GetPos(), Object->GetChar());
			}

			Screen.Print();
		}

		{
			std::list<ConsoleObject*>::iterator Start = Objects.begin();
			std::list<ConsoleObject*>::iterator End = Objects.end();

			for (; Start != End; ++Start)
			{
				ConsoleObject* Object = (*Start);

				if (false == Object->IsActive())
				{
					continue;
				}

				Object->Tick(1.0f);
			}
		}
	}
}