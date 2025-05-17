#pragma once
#include <string>
#include <vector>
#include "Weapon.h"
#include "Part.h"
#include "Skill.h"
#include "CharacterInfo.h"
#include "ElementType.h"
#include "Stat.h"

class Character {
public:
    Character(const std::string& name, ElementType element);

    std::string name;
    ElementType element;
    int level;
    int exp;
    int breakthroughStage; // 0~6단계

    // 스탯
    Stat hp;
    Stat atk;
    Stat def;
    float currentHp;

    // 기타 스탯
    float healingBonusGiven;
    float healingBonusReceived;
    float critRate;
    float critDamage;
    float damageBonus[9];  // 속성별 피해 증가 (속성별 배열)
    float resistance[9];   // 속성별 내성
    float cooldownReduction;
    float moveSpeed;
    float moveSpeedBonus;

    // 장비
    Weapon* weapon;
    Part* parts[5];

    // 스킬
    Skill normalAttack;
    Skill skill;
    Skill ult;

    // 해방 (5단계)
    bool liberation[5];

    // 스토리
    CharacterInfo info;

    // 메서드
    void levelUp();
    void gainExp(int amount);
    bool tryBreakthrough();

    float getFinalHp() const;
    float getFinalAtk() const;
    float getFinalDef() const;

    void printStatus() const; // 테스트 용

    void saveToJson(const std::string& filename) const;
    static Character loadFromJson(const std::string& filename);
};