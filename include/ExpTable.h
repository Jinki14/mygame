#pragma once
#include <vector>

class ExpTable {
public:
    static std::vector<int> table;

    static void init() {
        table = {0}; // 레벨 1은 0
        for (int i = 1; i <= 90; ++i) {
            int required = 100 + (i - 1) * 20;
            table.push_back(required);
        }
    }

    static int getExpForLevel(int level) {
        if (level >= table.size()) return 999999;
        return table[level];
    }
};