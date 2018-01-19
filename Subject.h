#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <iostream>
#include <list>
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::iterator;

class Observer;

class Subject
{
    public:
        virtual ~Subject();
        virtual void addObserver(Observer* obv);
        virtual void deleteObserver(Observer* obv);
        virtual void notifyObserver();
        void setchanged();
    protected:
        Subject();
        bool changed;
};

class WeatherData : public Subject
{
    public:
        WeatherData();
        ~WeatherData();
        void addObserver(Observer* obv);
        void deleteObserver(Observer* obv);
        void notifyObserver();
        void measurementsChanged();
        void setMeasurements(float temp,float humid,float pres);
        float getTemperature(){return temperature;}
        float gethumidity(){return humidity;}
        float getpressure(){return pressure;}
    private:
        list<Observer*>* pl_obvs;
        float temperature;
        float humidity;
        float pressure;
};

#endif
