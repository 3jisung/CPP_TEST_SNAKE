#include "Head.h"
#include <conio.h>
#include "ConsoleEngineCore.h"

Head::Head()
{
    SetChar('H');
    SetPos({ 0,0 });
}

Head::~Head()
{
}

void Head::Tick(float _Time)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = int4::Left;
        break;
    case 'd':
        MovePos = int4::Right;
        break;
    case 'w':
        MovePos = int4::Up;
        break;
    case 's':
        MovePos = int4::Down;
        break;
    case 'q':
        ConsoleEngineCore::EngineOff();
        break;
    default:
        break;
    }

    // ȭ�� ������ ������ �� üũ
    int4 tempPos = GetPos() + MovePos;
    if (tempPos.X < 0 || tempPos.X >= ConsoleEngineCore::Screen.ScreenScale().X)
    {
        MovePos.X = 0;
    }
    else if (tempPos.Y < 0 || tempPos.Y >= ConsoleEngineCore::Screen.ScreenScale().Y)
    {
        MovePos.Y = 0;
    }

    // �ݴ� �������� �̵��Ϸ� �ϴ� �� üũ �� ���� ���� �ֽ�ȭ
    if (currentDir + MovePos == int4{ 0, 0 })
    {
        MovePos = int4{ 0, 0 };
    }
    else
    {
        currentDir = MovePos;
    }

    AddPos(MovePos);
}