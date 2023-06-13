#pragma once
#include <iostream>
#include <vector>
#include "ConsoleMath.h"

class ConsoleScreen
{
public:
    ConsoleScreen();

    void Init(const int4& Scale, char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    int4 ScreenScale()
    {
        return Scale;
    }

    bool IsScreenOut(const int4& _Pos) const;

    void Print() const;

protected:


private:
    char BaseCh = ' ';
    int4 Scale;
    std::vector<std::vector<char>> ArrScreen;
};
