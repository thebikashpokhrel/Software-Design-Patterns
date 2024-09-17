/*
Designing a weather station based on Observer Pattern
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

// Observer Interface
class IObserver
{
public:
    virtual void update(float pressure, float temperature, float humidity) = 0;
};

// Subject Interface
class ISubject
{
public:
    virtual void registerObserver(IObserver *O) = 0;
    virtual void removeObserver(IObserver *O) = 0;
    virtual void notifyObservers() = 0;
};

// Display Element Interface
class IDisplayElement
{
public:
    virtual void display() = 0;
};

// WeatherData implementing Subject Interface
class WeatherData : public ISubject
{
    float pressure;
    float temperature;
    float humidity;

    std::vector<std::unique_ptr<IObserver>> Observers; // Array of observers that subscribe this subject

public:
    void registerObserver(IObserver *O) override
    {
        Observers.push_back(std::unique_ptr<IObserver>(O));
    }

    void removeObserver(IObserver *O) override
    {
        auto it = std::remove_if(Observers.begin(), Observers.end(),
                                 [O](const std::unique_ptr<IObserver> &elem)
                                 {
                                     return elem.get() == O;
                                 });
        Observers.erase(it, Observers.end());
    }

    void notifyObservers() override
    {
        for (const auto &O : Observers)
        {
            O->update(pressure, temperature, humidity);
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(float pres, float temp, float humd)
    {
        pressure = pres;
        temperature = temp;
        humidity = humd;
        measurementsChanged();
    }
};

// Concrete Display Class : currentConditionsDisplay
class currentCondtionsDisplay : public IDisplayElement, IObserver
{
    float temperature;
    float humidity;
    ISubject *weatherData;

public:
    currentCondtionsDisplay(ISubject *wd)
    {
        weatherData = wd;
        weatherData->registerObserver(this);
    }

    void update(float pres, float temp, float humd)
    {
        temperature = temp;
        humidity = humd;
        display();
    }

    void display()
    {
        std::cout << "Current conditions: Temperature = " << temperature << " deg F and humidity = " << humidity << std::endl;
    }
};

// Concrete Display Class: HeatIndex Display
class heatIndexDisplay : public IDisplayElement, IObserver
{
    float heatIndex;
    ISubject *weatherData;

    float computeHeatIndex(float t, float rh)
    {
        return -42.379 + 2.04901523 * t + 10.14333127 * rh - 0.22475541 * t * rh - 0.00683783 * t * t - 0.05481717 * rh * rh + 0.00122874 * t * t * rh + 0.00085282 * t * rh * rh - 0.00000199 * t * t * rh * rh;
    }

public:
    heatIndexDisplay(ISubject *wd)
    {
        weatherData = wd;
        weatherData->registerObserver(this);
    }

    void update(float presure, float temp, float humidity) override
    {
        heatIndex = computeHeatIndex(temp, humidity);
        display();
    }

    void display()
    {
        std::cout << "Current heat index is: " << heatIndex << std::endl;
    }
};

// Main function
int main()
{
    WeatherData *weatherData = new WeatherData();        // New weather data object
    currentCondtionsDisplay currentDisplay(weatherData); // New current display object
    heatIndexDisplay HIDisplay(weatherData);

    // Setting new measurements automatically notify observers and data is printed
    weatherData->setMeasurements(20, 98.3, 70);
    weatherData->setMeasurements(20.4, 9.3, 65);
    return 0;
}
