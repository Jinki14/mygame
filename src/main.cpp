#include <iostream>
#include <windows.h>

#include "Character.h"
#include "ExpTable.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    ExpTable::init();

    //Character ch("루미네", ElementType::Anemo);
    //ch.printStatus();

    //ch.gainExp(250);
    //ch.tryBreakthrough();

    //ch.printStatus();

    Character c("파이몬", ElementType::Anemo);
    c.gainExp(2145);
    c.tryBreakthrough();

    c.saveToJson("character.json");

    Character c2 = Character::loadFromJson("character.json");
    c2.printStatus();

    return 0;
}