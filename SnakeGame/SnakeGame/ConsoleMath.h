#pragma once

// 이녀석은 캡슐화된 클래스라기 보다는 기본자료형
class int4
{
public:
    // 리스 이니셜라이저
    // 리터럴 초기화가 되지 않는다.
    static const int4 Left/* = { -1, 0 }*/;
    static const int4 Right/* = { 1, 0 }*/;
    static const int4 Up/* = { 0, -1 }*/;
    static const int4 Down/* = { 0, 1 }*/;

public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    bool operator==(const int4& _Other)
    {
        return X == _Other.X &&
            Y == _Other.Y;
    }

    bool operator!=(const int4& _Other)
    {
        return X != _Other.X ||
            Y != _Other.Y;
    }


    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }

    int4 operator*(const int _Value) const
    {
        int4 Return;
        Return.X = X * _Value;
        Return.Y = Y * _Value;
        Return.Z = Z * _Value;
        Return.W = W * _Value;
        return Return;
    }


};

