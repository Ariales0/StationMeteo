#include "MyTempMock.h"

MyTempMock ::MyTempMock() : MAX_VALUE_POT(4095), INFERIOR_TEMPERATURE(-40), SUPERIOR_TEMPERATURE(80), INFERIOR_HUMIDITY(0), SUPERIOR_HUMIDITY(100)
{
  inferiorTemperature = INFERIOR_TEMPERATURE;
  supperiorTemperature = SUPERIOR_TEMPERATURE;
  inferiorHumidity = INFERIOR_HUMIDITY;
  supperiorHumidity = SUPERIOR_HUMIDITY;
  setUniteUsed(UNITY_FAHRENHEIT);
}

bool MyTempMock::init(int _inputPinUsed = MyTemp::DEFAUTLT_PIN, int _typeSensorUsed = DHT22)
{

    inputPinUsed = _inputPinUsed;
    typeSensorUsed = _typeSensorUsed;
    
    dht = new DHT(inputPinUsed, typeSensorUsed);
    if (!dht)
    {
        return false;
    }
    dht->begin();
    return true;
}

float MyTempMock::getTemperature()
{
  float temperature = inferiorTemperature + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorTemperature - inferiorTemperature);
  
  if(UniteUsed == UNITY_FAHRENHEIT)
  {
    temperature = (temperature * 1.8) +32;
  }
  return (temperature);
};

float MyTempMock::getHumidity()
{
  float humidity = inferiorHumidity + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorHumidity - inferiorHumidity);

  return (humidity);
};