
#include "CSpawner.h"
#include "CMonster.h"


CMonster* CSpawnerByClone::SpawnMoster()
{
    if (PrototypeInst == nullptr)
        return nullptr;

    return PrototypeInst->Clone();
}

CSpawnerByFunc::CSpawnerByFunc(SpawnCallback Func)
{
    SpawnMonster = Func;
}
