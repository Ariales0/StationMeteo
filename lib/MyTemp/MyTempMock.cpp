/**
 * Gestion de la simulation d'un capteur DTH
 *
 * @file MyTempMock.cpp
 * @author Lecourt Quentin
 * @brief Methode de la classe MyTempMock
 * @version 1.2.3
 * @date Création : 26/04/24
 * @date Dernière mise à jour : 29/04/2024
 */
#include "MyTempMock.h"

/**
 * Constructeur de la classe
 * Instanciation des constantes à la création de la classe
 */
MyTempMock ::MyTempMock() : MAX_VALUE_POT(4095), INFERIOR_TEMPERATURE(-40), SUPERIOR_TEMPERATURE(80), INFERIOR_HUMIDITY(0), SUPERIOR_HUMIDITY(100)
{
  inferiorTemperature = INFERIOR_TEMPERATURE;
  supperiorTemperature = SUPERIOR_TEMPERATURE;
  inferiorHumidity = INFERIOR_HUMIDITY;
  supperiorHumidity = SUPERIOR_HUMIDITY;
  setUniteUsed(UNITY_FAHRENHEIT);
}

/**
 * Initialisation init
 * Inialise les attribut protege de la classe MyTemp
 * 
 * @date Creation : 29/04/2024
 * @param int _inputPinUsed numero du faux capteur (potentiometre), la valeur par defaut DEFAUTLT_PIN de MyTemp
 * @param int _typeSensorUsed Type de capteur
 * 
 * @return true
 */
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

/**
 * Methode getTemperature()
 * Retourne la temperature simulée en fonction de l'impedance de potentiometre
 * 
 * @date Mise a jour : 29/04/2024
 * @brief La temperature est convertie en unite fahrenheit si c'est la temperature utilise
 * 
 * @return La temperature simulée
 */
float MyTempMock::getTemperature()
{
  float temperature = inferiorTemperature + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorTemperature - inferiorTemperature);
  
  if(UniteUsed == UNITY_FAHRENHEIT)
  {
    //Convertion Celsius - > Fahrenheit
    temperature = (temperature * 1.8) +32;
  }
  return (temperature);
};

/**
 * Methode getHumidity()
 * Retourne l'humidite simulée en fonction de l'impedance de potentiometre
 * 
 * @return L'humidite simulée
 */
float MyTempMock::getHumidity()
{
  float humidity = inferiorHumidity + (((float)analogRead(inputPinUsed)) / MAX_VALUE_POT) * (supperiorHumidity - inferiorHumidity);

  return (humidity);
};