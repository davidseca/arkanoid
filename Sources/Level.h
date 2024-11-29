#pragma once

#include <string>

// Possible levels
class Level {
public:
    enum class LevelType {
        EASY,
        MEDIUM,
        HARD
    };

    Level(LevelType type) : type(type) {}

    std::string getPath() const {
        switch (type) {
            case LevelType::EASY:
            case LevelType::MEDIUM:
            case LevelType::HARD:
            default:
                return "Resources/level-1.json";
        }
    }

private:
    LevelType type;
};