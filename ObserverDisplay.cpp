#include <iostream>
#include "ObserverDisplay.h"
#include "Subject.h"
using std::cin;
using std::cout;
using std::endl;

Observer::~Observer()
{

}

DisplayElement::~DisplayElement()
{

}

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject* sub)
{
    this->subject = sub;
    sub->addObserver(this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    subject->deleteObserver(this);
    if(0!=subject)
        delete subject;
}
void CurrentConditionsDisplay::update(float temp,float humid,float press)
{
    this->temperature = temp;
    this->humidity = humid;
    cout << "In CurrentConditionsDisplay::update " << this->temperature << ' ' << this-> humidity << endl; 
    display();
}

void CurrentConditionsDisplay::display()
{
    cout << "temperature: " << temperature << "F degrees and " << humidity << "% humidity" << endl;
}

