#pragma once
#include <string>
#include <vector>

class CharacterInfo {
public:
    std::string backstory;
    std::vector<std::string> unlockStories; // 돌파 1~6단계마다 열리는 서사
};