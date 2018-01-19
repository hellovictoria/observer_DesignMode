#include "ObserverDisplay.h"
#include "Subject.h"

int main()
{
    WeatherData *wd = new WeatherData();
    CurrentConditionsDisplay *ccd = new CurrentConditionsDisplay(wd);
    wd->addObserver(ccd);
    wd->setMeasurements(80,65,30.4f);
    ccd->display();
    wd->setMeasurements(82,70,29.2f);
    ccd->display();
    wd->setMeasurements(78,90,29.2f);
    ccd->display();
    return 0;
}
