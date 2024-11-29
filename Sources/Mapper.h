#pragma once

#include "LevelConfig.h"

#include <string>

// Mapper class
class Mapper {

public:

    static LevelConfig mapFromJson(const std::string& jsonString);

};