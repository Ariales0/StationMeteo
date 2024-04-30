/**
 * Classe de gestion d'un capteur de température DHT
 *
 * @file MyTemp.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe MyTemp
 * @version 1.2.3
 * @date Création : 02/03/2024
 * @date Dernière mise à jour : 29/04/2024
 */
#ifndef MYTEMP_H
#define MYTEMP_H

#include <DHT.h>
#include "Enums.cpp"

class MyTemp
{
public:
    MyTemp();
    bool init(int _inputPinUsed, int _typeSensorUsed);
    bool setUniteUsed(UNITY_TEMP uniteUsed);
    float getTemperature();
    float getHumidity();

protected:
    static const int DEFAUTLT_PIN;
    DHT *dht;
    int inputPinUsed;
    int UniteUsed;

    int typeSensorUsed;

private:
    static const float TEMPERATURE_ERREUR;
    static const float HUMIDITE_ERREUR;
    float lastTemperatureRead;
    float lastHumidityRead;
};
#endif