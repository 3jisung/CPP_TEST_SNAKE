// Snake.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleEngineCore.h"
#include "Head.h"
#include "BodyManager.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(511);

    ConsoleEngineCore::CreateObject<Head>();

    int4 screen = { 10, 10 };
    int bodyCount = 10;
    BodyManager::BodyInit(screen, bodyCount);

    // 이 함수만은 무조건 존재해야 합니다.
    ConsoleEngineCore::EngineStart(screen);

    ConsoleEngineCore::AllRelease();
}