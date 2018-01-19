#include <iostream>
#include "Subject.h"
#include "ObserverDisplay.h"
#include <list>
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::iterator;

Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::addObserver(Observer* obv)
{

}

void Subject::deleteObserver(Observer* obv)
{

}

void Subject::notifyObserver()
{

}

void Subject::setchanged()
{
    changed = true;
    cout << "changed: " << changed << endl;
}

WeatherData::WeatherData()
{
    pl_obvs = new list<Observer*>;
}

WeatherData::~WeatherData()
{

}

void WeatherData::addObserver(Observer* obv)
{
    if(NULL!=obv)
        pl_obvs->push_front(obv);
}

void WeatherData::deleteObserver(Observer* obv)
{
    if(NULL!=obv)
        pl_obvs->remove(obv);
}

void WeatherData::notifyObserver()
{
    if(changed)
    {
        list<Observer*>::iterator iter = pl_obvs->begin();
        for(;iter != pl_obvs->end();++iter)
        {
            cout << "notify" << endl;
            cout << this->getTemperature() << ' ' << this->gethumidity() << endl;
            (*iter)->update(this->temperature,this->humidity,this->pressure);
        }
    }
    changed = false;
}

void WeatherData::measurementsChanged()
{
    setchanged();
    notifyObserver();
}

void WeatherData::setMeasurements(float temp,float humid,float pres)
{
    temperature = temp;
    humidity = humid;
    pressure = pres;
    cout << "In WeatherData::setMeasurements " << this->temperature << ' ' << this->humidity << endl; 
    measurementsChanged();
}
