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

    SetPrevPos(GetPos());

    // ȭ�� ������ ������ �� üũ
    bool outCheck = ScreenOutControl(MovePos);

    // �ݴ� �������� �̵��Ϸ� �ϴ� �� üũ �� ���� ���� �ֽ�ȭ
    bool dirCheck = DirControl(MovePos);

    AddPos(MovePos);

    if (outCheck == false && dirCheck == false)
    {
        MovePart();
    }

    // �ٵ� ��ü�� �����ߴ� �� üũ
    bool triggerCheck = CheckBodyTrigger();

    if (triggerCheck)
    {
        AddBody();      // �ٵ� �߰�
    }
}

bool Head::ScreenOutControl(int4& MovePos)
{
    int4 tempPos = GetPos() + MovePos;
    if (tempPos.X < 0 || tempPos.X >= ConsoleEngineCore::Screen.ScreenScale().X)
    {
        MovePos.X = 0;

        return true;
    }
    else if (tempPos.Y < 0 || tempPos.Y >= ConsoleEngineCore::Screen.ScreenScale().Y)
    {
        MovePos.Y = 0;

        return true;
    }
    else
    {
        return false;
    }
}

bool Head::DirControl(int4& MovePos)
{
    if (currentDir + MovePos == int4{ 0, 0 })
    {
        MovePos = int4{ 0, 0 };

        return true;
    }
    else
    {
        currentDir = MovePos;

        return false;
    }
}

bool Head::CheckBodyTrigger()
{
    std::list<ConsoleObject*>::iterator Start = ConsoleEngineCore::Begin();
    std::list<ConsoleObject*>::iterator End = ConsoleEngineCore::End();

    ++Start;    // Head�� ����
    for (; Start != End; ++Start)
    {
        ConsoleObject* Object = (*Start);
        
        if (Object->GetPos() == GetPos() && Object->GetChar() == 'B')
        {
            delete Object;
            Object = nullptr;
            ConsoleEngineCore::Erase(Start);
            return true;
        }
    }

    return false;
}

void Head::AddBody()
{
    Part* currentPart = this;

    while (currentPart->GetNext() != nullptr)
    {
        currentPart = currentPart->GetNext();
    }

    Body* body = new Body();
    body->SetChar('b');
    body->SetPos({ currentPart->GetPrevPos().X, currentPart->GetPrevPos().Y});
    body->SetPrev(currentPart);
    currentPart->SetNext(body);
    //body->SetPrevPos(body->GetPos());
    ConsoleEngineCore::pushBackObject(body);
}

void Head::MovePart()
{
    Part* currentPart = this;

    while (currentPart->GetNext() != nullptr)
    {
        currentPart = currentPart->GetNext();

        currentPart->SetPrevPos(currentPart->GetPos());
        currentPart->SetPos(currentPart->GetPrev()->GetPrevPos());
    }
}