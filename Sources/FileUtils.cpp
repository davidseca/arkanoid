#include "FileUtils.h"

#include <fstream>

std::string FileUtils::getFileAsText(std::string filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}