#include "ConfigFile.h"


ConfigFile::ConfigFile(const std::string& filePath) {

    try
    {
        file.open(filePath);
    }
    catch (const std::exception&)
    {
        std::cerr << "�޷��������ļ��� " << filePath << std::endl;
        exit(1);
    }
    
}

ConfigFile::~ConfigFile() {
    file.close();
}

void ConfigFile::setValue(const std::string& key, const std::string& value) {
    configMap[key] = value;
}

std::string ConfigFile::getValue(const std::string& key) const {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second;
    }
    else {
        return "";
    }
}

void ConfigFile::writeToFile(const std::string& filePath) {
    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        std::cerr << "�޷����ļ��� " << filePath << std::endl;
        return;
    }

    for (const auto& pair : configMap) {
        outFile << pair.first << "=" << pair.second << std::endl;
    }

    outFile.close();
}

void ConfigFile::readFromFile(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "�޷����ļ��� " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue; // ������Ч��
        configMap[line.substr(0, pos)] = line.substr(pos + 1);
    }

    inFile.close();
}