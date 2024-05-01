/**
 * Classe Mock de simulation d'un capteur de temperature
 * Classe herite de MyTemp
 * @file MyTempMock.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe MyTempMock
 * @version 1.1.2
 * @date Création : 26/04/2024
 * @date Dernière mise à jour : 29/04/2024
 */
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
    const float MAX_VALUE_POT = 4095;
    const int INFERIOR_TEMPERATURE = -40; //Temperature minimale qu'un DHT22 peut lire
    const int SUPERIOR_TEMPERATURE = 80;  //Temperature maximale qu'un DHT22 peut lire
    const int INFERIOR_HUMIDITY = 0;
    const int SUPERIOR_HUMIDITY = 100;

    float inferiorTemperature;
    float supperiorTemperature;
    float inferiorHumidity;
    float supperiorHumidity;
};
#endif