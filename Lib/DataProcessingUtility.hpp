#pragma once
#include <string>
#include <vector>

class DataProcessor
{
    public:

    // string manipulation utils

    static std::vector<std::string> split(const std::string& s, const std::string& delimiter = ",");

    static std::string trim(const std::string& str, const std::string& whitespace = " \t");

    static std::string remove_char(const std::string& data, char ch);


    // check if a string is a valid double 

    static bool isAllDigits(const std::string& data);

    static bool isDataDouble(const std::string& data);


    // populate double vector with NaN

    static void fillNaN(std::vector<double>& doubleVector, size_t length);


    // populate double vector with data if data is a valid double otherwise with NaN

    static bool isDataNotEmpty(std::vector<std::string>& data);

    static void fillIfDouble(std::vector<double>& doubleVector, std::vector<std::string>& data);

    static void fillNaNifLengthNotEqual(std::vector<double>& doubleVector, size_t length);

    static void populateDoubleVector(std::vector<double>& doubleVector, std::vector<std::string>& data, size_t length);
};
