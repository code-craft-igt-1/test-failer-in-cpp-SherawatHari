#include <assert.h>
#include <string>
#include <iostream>

namespace WeatherSpace {
class IWeatherSensor {
 public:
    virtual double TemperatureInC() const = 0;
    virtual int Precipitation() const = 0;
    virtual int Humidity() const = 0;
    virtual int WindSpeedKMPH() const = 0;
};

/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development

class SensorStub : public IWeatherSensor {
 private:
    double temperature_;
    int precipitation_;
    int humidity_;
    int windSpeed_;

 public:
    SensorStub(double temperature, int precipitation, int humidity, int windSpeed)
        : temperature_(temperature), precipitation_(precipitation),
          humidity_(humidity), windSpeed_(windSpeed) {}

    double TemperatureInC() const override {
        return temperature_;
    }

    int Precipitation() const override {
        return precipitation_;
    }

    int Humidity() const override {
        return humidity_;
    }

    int WindSpeedKMPH() const override {
        return windSpeed_;
    }
};

// This is a function to predict the weather, based on readings
// from a sensor

std::string Report(const IWeatherSensor& sensor) {
    int precipitation = sensor.Precipitation();
    // precipitation < 20 is a sunny day
    std::string report = "Sunny day";

    if (sensor.TemperatureInC() > 25) {
        if (precipitation >= 20 && precipitation < 60)
            report = "Partly cloudy";
        else if (precipitation >= 60)
            report = "Rainy day";
        else if (sensor.WindSpeedKMPH() > 50)
            report = "Alert, Stormy with heavy rain";
    }
    return report;
}

// Test a rainy day

void TestRainy() {
    SensorStub sensor(26, 70, 72, 52);
    std::string report = Report(sensor);
    std::cout << report << std::endl;
    assert(report.find("Rainy") != std::string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    SensorStub sensor(26, 70, 72, 40);

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    std::string report = Report(sensor);
    std::cout << report << std::endl;
    assert(report.find("Rainy") != std::string::npos);
}
}  // namespace WeatherSpace

int main() {
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitationAndLowWindspeed();
    std::cout << "All is well\n";
    return 0;
}
