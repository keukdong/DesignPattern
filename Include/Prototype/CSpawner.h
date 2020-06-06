#pragma once


class CMonster;

class CSpawnerByClone
{
public:
    CSpawnerByClone(CMonster* InPrototypeInst)
        : PrototypeInst(InPrototypeInst)
    {};

    virtual ~CSpawnerByClone() = default;

public:
    CMonster* SpawnMoster();

private:
    CMonster* PrototypeInst;
};

class CSpawnerByFunc
{
    // using (*SpawnCallback)() = CMonster * ;
    typedef CMonster* (*SpawnCallback)();
public:
    CSpawnerByFunc(SpawnCallback Func);  /* = CSpawnerByFunc(CMonster*(*Func)());*/
    virtual ~CSpawnerByFunc() = default;

public:
    SpawnCallback SpawnMonster;
};

class CSpawnerBase
{
public:
    virtual ~CSpawnerBase() {};
    virtual CMonster* SpawnMonster() = 0;
};

template <class T>
class CSpawnerTemplate : public CSpawnerBase
{
public:
    virtual CMonster* SpawnMonster();
};

template<class T>
inline CMonster * CSpawnerTemplate<T>::SpawnMonster()
{
    // T�� CMonster�� ��Ӱ��迡 ���� �����͸� ���?
    //return new T;

    auto Monster = new T;
    auto CastedMonster = dynamic_cast<CMonster*>(Monster);

    if (CastedMonster == nullptr)
        return nullptr;

    return CastedMonster;
}
