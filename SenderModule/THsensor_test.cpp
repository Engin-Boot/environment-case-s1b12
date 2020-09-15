#include "../Lib/catch/catch.hpp"
#include "CSVReader.hpp"
#include "../Lib/DataProcessingUtility.hpp"
#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <cmath>

struct TemperatureHumiditySensorData
{
    int size = 2;
    double temperature;
    double humidity;
};

TemperatureHumiditySensorData GetSensorData(Reader* reader, TemperatureHumiditySensorData& th_SensorData)
{
    std::string raw_data = reader->fetch_current_row();
    std::vector<std::string> data_after_split = DataProcessor::split(raw_data);

    std::vector<std::string> data_after_trim;

    for(auto data : data_after_split)
    {
        data_after_trim.push_back(DataProcessor::trim(data));
    }
    
    std::vector<double> doubleDataVector;

    if(data_after_trim.size() > 1)
        DataProcessor::populateDoubleVector(doubleDataVector, data_after_trim, th_SensorData.size);
    else
        DataProcessor::fillNaN(doubleDataVector, th_SensorData.size);
    
    th_SensorData.temperature = doubleDataVector[0];
    th_SensorData.humidity = doubleDataVector[1];
    return th_SensorData;
}

TEST_CASE("Valid double data with leading and trailing spaces are read properly")
{
    std::vector<std::pair<double, double>> expected_data = {std::make_pair(-3,85), std::make_pair(12,45), std::make_pair(25.5, 60)};
    std::string filepath = "sender_testdata/THdata0.csv";
    CSVReader* reader = new CSVReader(filepath);
    TemperatureHumiditySensorData th_SensorData; 
    int index = 0;
    while(reader->good())
    {
        TemperatureHumiditySensorData sd = GetSensorData(reader, th_SensorData);
        REQUIRE(expected_data[index].first == sd.temperature);
        REQUIRE(expected_data[index].second == sd.humidity);
        index++;
    }
}


TEST_CASE("(Incomplete Data) When data either does not have temperature or humidity, then NaN is returned")
{
    std::string filepath = "sender_testdata/THdata1.csv";
    CSVReader* reader = new CSVReader(filepath);
    TemperatureHumiditySensorData th_SensorData; 
    while(reader->good())
    {
        TemperatureHumiditySensorData sd = GetSensorData(reader, th_SensorData);
        REQUIRE(std::isnan(sd.temperature));
        REQUIRE(std::isnan(sd.humidity));
    }
}

TEST_CASE("When data has empty lines and special chars, then NaN is returned")
{
    std::string filepath = "sender_testdata/THdata2.csv";
    CSVReader* reader = new CSVReader(filepath);
    TemperatureHumiditySensorData th_SensorData; 
    while(reader->good())
    {
        TemperatureHumiditySensorData sd = GetSensorData(reader, th_SensorData);
        REQUIRE(std::isnan(sd.temperature));
        REQUIRE(std::isnan(sd.humidity));
    }
}