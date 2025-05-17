#pragma once
#include <string>
#include "ElementType.h"

enum class WeaponType { Sword, Bow, Polearm, Catalyst, Claymore };

class Weapon {
public:
    std::string name;
    int level;
    int exp;
    WeaponType type;
    float attackPower;
    std::string mainStatName;
    float mainStatValue;
    std::string skillDescription;

    // 돌파 여부에 따라 스탯 보정 가능
};