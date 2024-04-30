#ifndef MYTEMP_MOCK_H
#define MYTEMP_MOCK_H

#include <Arduino.h>

#include "MyTemp.h"
class MyTempMock : public MyTemp
{
public:
    MyTempMock();
    ~MyTempMock(){};
    bool init(int _inputPinUsed, int _typeSensorUsed);
    float getTemperature();
    float getHumidity();

private:
    const float MAX_VALUE_POT;
    const int INFERIOR_TEMPERATURE;
    const int SUPERIOR_TEMPERATURE;
    const int INFERIOR_HUMIDITY;
    const int SUPERIOR_HUMIDITY;

    float inferiorTemperature;
    float supperiorTemperature;
    float inferiorHumidity;
    float supperiorHumidity;
};
#endif