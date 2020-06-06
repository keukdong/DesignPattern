
#pragma once

#include "DesignPattern.h"

#include "CSpawner.h"
#include "CDemon.h"

int main_prototype()
{
    /*
        1. 
        + spawner class를 몬스터마다 따로 만들지 않아도 됨

        - 각 클래스안에서 clone함수를 구현해야한다 
    */
    CMonster* DemonInstance = new CDemon;
    CSpawnerByClone* DemonSpawner = new CSpawnerByClone(DemonInstance);

    CMonster* SpawnedDemonInstance = DemonSpawner->SpawnMoster();

    /*
        2.
        + 함수를 Spanwer에게 넘겨준다.
    */

    auto SpawnDemon = []() -> CMonster*
    {
        return new CDemon;
    };

    CSpawnerByFunc* DemonSpawnerByFunc = new CSpawnerByFunc(SpawnDemon);
    CMonster* SpawnedDemonInstance2 = DemonSpawnerByFunc->SpawnMonster();

    /*
        3.
        + 함수를 작성할 필요없이 자료형을 template에 넘기기만 하면된다.
        - type check가 필요하다.
    */
    CSpawnerBase* DemonSpawnerTemplate = new CSpawnerTemplate<CDemon>();
    CMonster* SpawnedDemonInstacne3 = DemonSpawnerTemplate->SpawnMonster();

    CSpawnerBase* TestSpawnerTemplate = new CSpawnerTemplate<CTest>();  /* 전혀 관계없는 자료형인 경우 */
    CMonster* SpawnedTestInstance = TestSpawnerTemplate->SpawnMonster();

    return 0;
}