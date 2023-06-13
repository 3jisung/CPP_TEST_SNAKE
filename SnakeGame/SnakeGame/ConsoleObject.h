#pragma once
#include "ConsoleMath.h"
#include "ConsoleScreen.h"

// 위치와 관련된 객체들이 상속받는다.
class ConsoleObject
{
public:
    virtual ~ConsoleObject()
    {

    }

    char GetChar()
    {
        return RenderChar;
    }

    void SetChar(char _Text)
    {
        RenderChar = _Text;
    }

    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }

    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    void On()
    {
        IsActiveValue = true;
    }

    void Off()
    {
        IsActiveValue = false;
    }

    bool IsActive()
    {
        return IsActiveValue;
    }

    virtual void Tick(float _Time)
    {
    }

private:
    int4 Pos;
    char RenderChar = ' ';
    bool IsActiveValue = true;
};

