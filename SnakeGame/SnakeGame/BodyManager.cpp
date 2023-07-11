#include "BodyManager.h"
#include <cstdlib>

void BodyManager::BodyInit(const int4& _Scale, const int bodyCount)
{
    // 랜덤한 위치에 바디 생성
    srand(time(NULL));
    int4 tempPosArr[10];
    for (size_t i = 0; i < bodyCount; i++)
    {
        int posX = rand() % _Scale.X;
        int posY = rand() % _Scale.Y;

        if (posX == 0 && posY == 0)
        {
            i -= 1;
            continue;
        }

        Body* body = new Body();
        body->SetChar('B');
        body->SetPos({ posX, posY });
        tempPosArr[i] = body->GetPos();
        //ConsoleEngineCore::pushBackObject(body);

        if (i == 0)
        {
            ConsoleEngineCore::pushBackObject(body);
            continue;
        }

        for (size_t j = 0; j < i; j++)
        {
            if (tempPosArr[i] == tempPosArr[j])
            {
                i -= 1;
                delete body;
                break;
            }

            if (j == i - 1 && tempPosArr[i] != tempPosArr[j])
            {
                ConsoleEngineCore::pushBackObject(body);
            }
        }
    }
}