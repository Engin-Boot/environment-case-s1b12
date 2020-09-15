#pragma once
#include <string>
#include <vector>

// string manipulation utils

std::vector<std::string> split(const std::string& s, const std::string& delimiter = ",");

std::string trim(const std::string& str, const std::string& whitespace = " \t");

std::string remove_char(const std::string& data, char ch);


// check if a string is a valid double 

bool isAllDigits(const std::string& data);

bool isDataDouble(const std::string& data);


// populate double vector with NaN

void fillNaN(std::vector<double>& doubleVector, size_t length);


// populate double vector with data if data is a valid double otherwise with NaN

bool isDataNotEmpty(std::vector<std::string>& data);

void fillIfDouble(std::vector<double>& doubleVector, std::vector<std::string>& data);

void fillNaNifLengthNotEqual(std::vector<double>& doubleVector, size_t length);

void populateDoubleVector(std::vector<double>& doubleVector, std::vector<std::string>& data, size_t length);
