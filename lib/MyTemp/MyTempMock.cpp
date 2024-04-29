#include "MyTempMock.h"
MyTempMock ::MyTempMock() : MAX_VALUE_POT(4095), INFERIOR_TEMPERATURE(-80), SUPERIOR_TEMPERATURE(40), INFERIOR_HUMIDITY(0), SUPERIOR_HUMIDITY(100)
{
  inferiorTemperature = INFERIOR_TEMPERATURE;
  supperiorTemperature = SUPERIOR_TEMPERATURE;
  inferiorHumidity = INFERIOR_HUMIDITY;
  supperiorHumidity = SUPERIOR_HUMIDITY;
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