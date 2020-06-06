
#pragma once

#include "DesignPattern.h"

#include "CSpawner.h"
#include "CDemon.h"

int main_prototype()
{
    /*
        1. 
        + spawner class�� ���͸��� ���� ������ �ʾƵ� ��

        - �� Ŭ�����ȿ��� clone�Լ��� �����ؾ��Ѵ� 
    */
    CMonster* DemonInstance = new CDemon;
    CSpawnerByClone* DemonSpawner = new CSpawnerByClone(DemonInstance);

    CMonster* SpawnedDemonInstance = DemonSpawner->SpawnMoster();

    /*
        2.
        + �Լ��� Spanwer���� �Ѱ��ش�.
    */

    auto SpawnDemon = []() -> CMonster*
    {
        return new CDemon;
    };

    CSpawnerByFunc* DemonSpawnerByFunc = new CSpawnerByFunc(SpawnDemon);
    CMonster* SpawnedDemonInstance2 = DemonSpawnerByFunc->SpawnMonster();

    /*
        3.
        + �Լ��� �ۼ��� �ʿ���� �ڷ����� template�� �ѱ�⸸ �ϸ�ȴ�.
        - type check�� �ʿ��ϴ�.
    */
    CSpawnerBase* DemonSpawnerTemplate = new CSpawnerTemplate<CDemon>();
    CMonster* SpawnedDemonInstacne3 = DemonSpawnerTemplate->SpawnMonster();

    CSpawnerBase* TestSpawnerTemplate = new CSpawnerTemplate<CTest>();  /* ���� ������� �ڷ����� ��� */
    CMonster* SpawnedTestInstance = TestSpawnerTemplate->SpawnMonster();

    return 0;
}