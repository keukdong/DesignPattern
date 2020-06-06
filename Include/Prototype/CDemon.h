
#pragma once

#include "CMonster.h"

class CDemon : public CMonster
{
public:
    CDemon() = default;
    virtual ~CDemon() override = default;

public:
    CMonster* Clone() override;
};
