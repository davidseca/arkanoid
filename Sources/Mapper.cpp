#include "Mapper.h"

#include <sstream>
#include <map>

LevelConfig Mapper::mapFromJson(const std::string& jsonString) {
        std::map<std::string, std::string> jsonMap;
        std::stringstream ss(jsonString);
        std::string key, value;

        while (ss >> key >> value) {
            jsonMap[key] = value;
        }

        LevelConfig config;
        config.ballStartX = std::stof(jsonMap["\"ballStartX\""]);
        config.ballStartY = std::stof(jsonMap["\"ballStartY\""]);
        config.paddleStartX = std::stof(jsonMap["\"paddleStartX\""]);
        config.paddleStartY = std::stof(jsonMap["\"paddleStartY\""]);
        config.paddleWidth = std::stof(jsonMap["\"paddleWidth\""]);
        config.paddleHeight = std::stof(jsonMap["\"paddleHeight\""]);
        config.paddleSpeed = std::stof(jsonMap["\"paddleSpeed\""]);
        config.wallThickness = std::stof(jsonMap["\"wallThickness\""]);
        config.brickRows = std::stoi(jsonMap["\"brickRows\""]);
        config.brickCols = std::stoi(jsonMap["\"brickCols\""]);
        config.brickWidth = std::stof(jsonMap["\"brickWidth\""]);
        config.brickHeight = std::stof(jsonMap["\"brickHeight\""]);
        config.brickStartX = std::stof(jsonMap["\"brickStartX\""]);
        config.brickStartY = std::stof(jsonMap["\"brickStartY\""]);

        return config;
    }