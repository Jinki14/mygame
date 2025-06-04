#include <iostream>
#include <windows.h>

#include "GameManager.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    GameManager game;
    game.run(); // 내부에서 로그인 → 메인 메뉴 → 각 기능 루프
    return 0;
}