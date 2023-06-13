#include "ConsoleScreen.h"


ConsoleScreen::ConsoleScreen()
{

}

void ConsoleScreen::Init(const int4& _Scale, char _BaseCh)
{
    BaseCh = _BaseCh;

    Scale = _Scale;

    ArrScreen.resize(_Scale.Y);

    for (size_t y = 0; y < ArrScreen.size(); y++)
    {
        ArrScreen[y].resize(_Scale.X + 1);
    }

    Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
    if (true == IsScreenOut(_Pos))
    {
        return;
    }

    ArrScreen[static_cast<int>(_Pos.Y)][static_cast<int>(_Pos.X)] = _Ch;
}

void ConsoleScreen::Clear()
{
    system("cls");
    for (size_t y = 0; y < Scale.Y; y++)
    {
        for (size_t x = 0; x < Scale.X; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][Scale.X] = 0;
    }
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (Scale.X <= _Pos.X)
    {
        return true;
    }

    if (Scale.Y <= _Pos.Y)
    {
        return true;
    }

    return false;
}


void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < ArrScreen.size(); y++)
    {
        const char* Ptr = &ArrScreen[y][0];
        printf_s(Ptr);
        printf_s("\n");
    }
}
