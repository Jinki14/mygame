#pragma once

struct Stat {
    float base;
    float percent;
    float flat;

    float getFinalStat() const {
        return base * (1.0f + percent / 100.0f) + flat;
    }
};