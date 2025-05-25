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

    std::string name;           // 캐릭터 명
    ElementType element;        // 원소 타입
    int level;                  // 레벨
    int exp;                    // 경험치
    int breakthroughStage;      // 0~6단계

    // 스탯
    Stat hp;                    // 체력
    Stat atk;                   // 공격력
    Stat def;                   // 방어력
    float currentHp;            // 현재 체력

    // 기타 스탯
    float healingBonusGiven;        // 치유 보너스
    float healingBonusReceived;     // 받는 치유 보너스
    float critRate;                 // 치명타 확률
    float critDamage;               // 치명타 피해
    float damageBonus[9];           // 속성별 피해 증가 (속성별 배열)
    float resistance[9];            // 속성별 내성
    float cooldownReduction;        // 재사용 대기 시간 감소
    float moveSpeed;                // 이동 속도
    float moveSpeedBonus;           // 이동 속도 보너스

    // 장비
    Weapon* weapon;                 // 무기
    Part* parts[5];                 // 성유물(추후 이름 변경 예정)

    // 스킬
    Skill normalAttack;             // 일반 공격
    Skill skill;                    // 전투 스킬
    Skill ult;                      // 전투 궁극기

    // 해방 (5단계)
    bool liberation[5];             // 별자리 해금

    // 스토리
    CharacterInfo info;             // 캐릭터 정보

    // 메서드
    void levelUp();                 // 레벨 업
    void gainExp(int amount);       // 경험치 얻기
    bool tryBreakthrough();         // 돌파

    float getFinalHp() const;       // 최종 체력 얻기
    float getFinalAtk() const;      // 최종 공격력 얻기
    float getFinalDef() const;      // 최종 방어력 얻기

    void printStatus() const;       // 테스트 용

    void saveToJson(const std::string& filename) const;
    static Character loadFromJson(const std::string& filename);
};