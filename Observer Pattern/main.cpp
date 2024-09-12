/*
Designing a weather station based on Observer Pattern
*/

#include <iostream>
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

    void setMeasurements(float pressure, float temperature, float humidity)
    {
        pressure = pressure;
        temperature = temperature;
        humidity = humidity;
        measurementsChanged();
    }
};