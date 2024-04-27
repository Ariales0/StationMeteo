#ifndef MYTEMP_MOCK_H
#define MYTEMP_MOCK_H

#include <Arduino.h>

#include "MyTemp.h"
class MyTempMock : public MyTemp
{
private:
    const float MAX_VALUE_POT = 4095;
    const int INFERIOR_TEMPERATURE = -80;
    const int SUPERIOR_TEMPERATURE = 40;
    const int INFERIOR_HUMIDITY = 0;
    const int SUPERIOR_HUMIDITY = 100;

public:
    MyTempMock();
    ~MyTempMock(){};

    float getTemperature();
    float getHumidity();

private:
    float inferiorTemperature = INFERIOR_TEMPERATURE;
    float supperiorTemperature = SUPERIOR_TEMPERATURE;
    float inferiorHumidity = INFERIOR_HUMIDITY;
    float supperiorHumidity = SUPERIOR_HUMIDITY;
};
#endif