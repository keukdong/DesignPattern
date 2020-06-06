#pragma once


class CMonster
{
public:
    CMonster() = default;
    virtual ~CMonster() = 0;

public:
    virtual CMonster* Clone() =0;
};

class CTest
{
public:
    CTest() = default;
    virtual ~CTest() = default;
};