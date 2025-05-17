#include <iostream>
#include <fstream>

#include "Character.h"
#include "ExpTable.h"

#include "json.hpp"

using json = nlohmann::json;

// 저장
void Character::saveToJson(const std::string& filename) const {
    json j;
    j["name"] = name;
    j["element"] = static_cast<int>(element);
    j["level"] = level;
    j["exp"] = exp;
    j["breakthroughStage"] = breakthroughStage;

    j["hp"] = { hp.base, hp.percent, hp.flat };
    j["atk"] = { atk.base, atk.percent, atk.flat };
    j["def"] = { def.base, def.percent, def.flat };

    j["currentHp"] = currentHp;
    j["healingBonusGiven"] = healingBonusGiven;
    j["healingBonusReceived"] = healingBonusReceived;
    j["critRate"] = critRate;
    j["critDamage"] = critDamage;

    for (int i = 0; i < 9; ++i) {
        j["damageBonus"][i] = damageBonus[i];
        j["resistance"][i] = resistance[i];
    }

    j["cooldownReduction"] = cooldownReduction;
    j["moveSpeed"] = moveSpeed;
    j["moveSpeedBonus"] = moveSpeedBonus;

    for (int i = 0; i < 5; ++i) {
        j["liberation"][i] = liberation[i];
    }

    // TODO: weapon, parts, skill 등은 이후에 따로 직렬화

    std::ofstream file(filename);
    file << j.dump(4); // 보기 좋게 들여쓰기
    file.close();
}

// 불러오기
Character Character::loadFromJson(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    file.close();

    Character c(j["name"], static_cast<ElementType>(j["element"]));
    c.level = j["level"];
    c.exp = j["exp"];
    c.breakthroughStage = j["breakthroughStage"];

    c.hp = { j["hp"][0], j["hp"][1], j["hp"][2] };
    c.atk = { j["atk"][0], j["atk"][1], j["atk"][2] };
    c.def = { j["def"][0], j["def"][1], j["def"][2] };

    c.currentHp = j["currentHp"];
    c.healingBonusGiven = j["healingBonusGiven"];
    c.healingBonusReceived = j["healingBonusReceived"];
    c.critRate = j["critRate"];
    c.critDamage = j["critDamage"];

    for (int i = 0; i < 9; ++i) {
        c.damageBonus[i] = j["damageBonus"][i];
        c.resistance[i] = j["resistance"][i];
    }

    c.cooldownReduction = j["cooldownReduction"];
    c.moveSpeed = j["moveSpeed"];
    c.moveSpeedBonus = j["moveSpeedBonus"];

    for (int i = 0; i < 5; ++i) {
        c.liberation[i] = j["liberation"][i];
    }

    // TODO: weapon, parts, skill 등은 추후 확장
    return c;
}

// 돌파 수치를 별로 알려줌
std::string breakthroughStars(int stage) {
    std::string result;
    for (int i = 0; i < 6; ++i) {
        result += (i < stage) ? "★" : "☆";
        if(i<5) result += " ";
    }
    return result;
}

// 경험치에 따른 경험치바
std::string experienceBar(int currentExp, int maxExp, int width = 20) {
    int filled = static_cast<int>((float)currentExp / maxExp * width);
    std::string bar = "[";
    for (int i = 0; i < width; ++i) {
        bar += (i < filled) ? "=" : " ";
    }
    bar += "]";
    return bar;
}

// 생성자
Character::Character(const std::string& name, ElementType element)
    : name(name), element(element), level(1), exp(0), breakthroughStage(0),
      currentHp(100), healingBonusGiven(0), healingBonusReceived(0),
      critRate(0), critDamage(50), cooldownReduction(0),
      moveSpeed(100), moveSpeedBonus(0), weapon(nullptr)
{
    // 초기화
    hp = {100, 0, 0};   // base, percent, flat
    atk = {10, 0, 0};
    def = {10, 0, 0};

    for (int i = 0; i < 9; ++i) {
        damageBonus[i] = 0;
        resistance[i] = 0;
    }

    for (int i = 0; i < 5; ++i)
        liberation[i] = false;

    for (int i = 0; i < 5; ++i)
        parts[i] = nullptr;
}

// 경험치 획득
void Character::gainExp(int amount) {
    exp += amount;
    while (exp >= ExpTable::getExpForLevel(level)) {
        exp -= ExpTable::getExpForLevel(level);
        levelUp();
    }
}

// 레벨업
void Character::levelUp() {
    if (level >= 90) return;
    ++level;
    hp.base += 10;
    atk.base += 2;
    def.base += 2;
    std::cout << name << " 레벨업! 현재 레벨: " << level << std::endl;
}

// 돌파 시도
bool Character::tryBreakthrough() {
    static int thresholds[6] = {20, 40, 50, 60, 70, 80};
    if (breakthroughStage < 6 && level >= thresholds[breakthroughStage]) {
        ++breakthroughStage;
        std::cout << name << " 돌파 성공! 현재 돌파 단계: " << breakthroughStage << std::endl;
        return true;
    }
    return false;
}

// 최종 스탯 계산
float Character::getFinalHp() const {
    return hp.getFinalStat();
}

float Character::getFinalAtk() const {
    return atk.getFinalStat();
}

float Character::getFinalDef() const {
    return def.getFinalStat();
}

// 상태 출력
void Character::printStatus() const {
    std::cout << "\n" << name << std::endl;
    std::cout << breakthroughStars(breakthroughStage) << std::endl;
    std::cout << "Lv " << level << " / 90" << std::endl;
    std::cout << experienceBar(exp, 100) << "  (" << exp << "/100)" << std::endl;
    std::cout << "속성: " << elementToString(element) << "\n" << std::endl;

    std::cout << "HP 최대치           " << getFinalHp() << std::endl;
    std::cout << "공격력              " << getFinalAtk() << std::endl;
    std::cout << "방어력              " << getFinalDef() << std::endl;
}