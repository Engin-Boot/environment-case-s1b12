#pragma once
#include "Reader.hpp"
#include <iostream>
#include <fstream>

class CSVReader : public Reader
{
    private:
        std::string filepath;
        std::ifstream readFromFile;
    public:
        explicit CSVReader(const std::string& filepath);
        void closeFileIfOpen(std::ifstream& readFromFile);
        bool good();
        std::string fetch_current_row() override;
        ~CSVReader();
};
