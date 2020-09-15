#include <string>
#include <vector>
#include <iostream>
#include "SenderModule/CSVReader.hpp"
#include "SenderModule/Timer.hpp"
#include "Lib/DataProcessingUtility.hpp"
#define SENDER_LATENCY 2

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


int main()
{
    std::string filepath = "testdata/temperature-humidity.csv";
    CSVReader* reader = new CSVReader(filepath);
    TemperatureHumiditySensorData th_SensorData;
    Timer timer;
    while(reader->good())
    {
        timer.sleep_for(SENDER_LATENCY);
        TemperatureHumiditySensorData sd = GetSensorData(reader, th_SensorData);
        std::cout << sd.temperature << ", " << sd.humidity << std::endl;
    }
    return 0;
}