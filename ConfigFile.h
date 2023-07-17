#pragma once

#ifndef ConfigFile_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define ConfigFile_H
//∂¡–¥≈‰÷√Œƒº˛
class ConfigFile
{


    public:
        ConfigFile(const std::string& filePath);

        ~ConfigFile();

        void setValue(const std::string& key, const std::string& value);

        std::string getValue(const std::string& key) const;

        void writeToFile(const std::string& filePath);    

        void readFromFile(const std::string& filePath);

    private:
            std::ifstream file;
            std::map<std::string, std::string> configMap;

};

#endif // ConfigFile_H
