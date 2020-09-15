#include "DataProcessingUtility.hpp"
#include <algorithm>
#include <limits>

// ********************************************* String Manipulation Utils ******************************************************************** //

std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
    std::vector<std::string> after_split;
    size_t last = 0; 
    size_t next = 0; 
    while ((next = s.find(delimiter, last)) != std::string::npos) 
    {   
        after_split.push_back(s.substr(last, next-last));   
        last = next + 1; 
    } 
    std::string temp = remove_char(s.substr(last), '\r');
    after_split.push_back(temp);
    return after_split;
}

std::string trim(const std::string& str,
                 const std::string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string remove_char(const std::string& data, char ch)
{
    std::string data_copy = data;
    data_copy.erase(std::remove(data_copy.begin(), data_copy.end(), ch), data_copy.end());
    return data_copy;
}


// ************************************************* Check If a String Is a Valid Double *********************************************** // 

bool isAllDigits(const std::string& data)
{
    for(char ch : data)
    {
        if(!isdigit(ch)) return false;
    }
    return true;
}


bool isDataDouble(const std::string& data)
{
    size_t point_count = std::count(data.begin(), data.end(), '.');
    std::string point_removed = remove_char(data, '.');
    std::string negative_removed = remove_char(point_removed, '-');
    return (point_count <= 1) && isAllDigits(negative_removed); 
}


// *************************************************Populate Double Vector With NaN ******************************************************************* //

void fillNaN(std::vector<double>& doubleVector, size_t length)
{
    for(int i = 0; i < length; i++)
    {
        doubleVector.push_back(std::numeric_limits<double>::quiet_NaN());
    }
}


// ****************************************** Populate Double Vector With Data If Data Is a Valid Double Otherwise With NaN *********************************************************** //

bool isDataNotEmpty(std::vector<std::string>& data)
{
    for(auto i : data)
    {
        if(i.length() == 0) return false;
    }
    return true;
}

void fillIfDouble(std::vector<double>& doubleVector, std::vector<std::string>& data)
{
    for(auto d : data)
    {
        if(isDataDouble(d))
            doubleVector.push_back(stod(d));
    }
}

void fillNaNifLengthNotEqual(std::vector<double>& doubleVector, size_t length)
{
    if(doubleVector.size() != length) 
    {   
        doubleVector.erase(doubleVector.begin(), doubleVector.end());
        fillNaN(doubleVector, length);
    }
}

void populateDoubleVector(std::vector<double>& doubleVector, std::vector<std::string>& data, size_t length)
{
    if(isDataNotEmpty(data))
    {
        fillIfDouble(doubleVector, data);
        fillNaNifLengthNotEqual(doubleVector, length);
    }
    else
    {
        fillNaN(doubleVector, length);
    }   
}
