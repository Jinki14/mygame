#pragma once
#include <string>

class Skill {
public:
    std::string name;
    std::string description;
    float cooldown; // 초 단위
};