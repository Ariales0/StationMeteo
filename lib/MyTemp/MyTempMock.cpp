#include "MyTempMock.h"

MyTempMock ::MyTempMock()
{
  setUniteUsed(UNITY_FAHRENHEIT);
}

float MyTempMock::getTemperature()
{

  float temperature = inferiorTemperature + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorTemperature - inferiorTemperature);
  return (temperature);
};

float MyTempMock::getHumidity()
{
  float humidity = inferiorHumidity + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorHumidity - inferiorHumidity);

  return (humidity);
};