#ifndef OBSERVERDISPLAY_H_
#define OBSERVERDISPLAY_H_
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Subject;
class WeatherData;

//pure virtual class, cannot be instantiated.
class Observer
{
    public:
        virtual ~Observer();
        virtual void update(float temp,float humid,float press)=0; //pure virtual function
};

class DisplayElement
{
    public:
        virtual ~DisplayElement();
        virtual void display()=0;
};

class CurrentConditionsDisplay : public Observer,public DisplayElement
{
    public:
        CurrentConditionsDisplay(Subject* sub);
        ~CurrentConditionsDisplay();
        void update(float temp,float humid,float press);
        void display();
    private:
        float temperature;
        float humidity;
        Subject *subject;
};

#endif
