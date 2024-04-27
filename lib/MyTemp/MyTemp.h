/**
 * Classe de gestion d'un capteur de température DHT
 *
 * @file MyTemp.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe MyTemp
 * @version 1.1
 * @date Création : 02/03/2024
 * @date Dernière mise à jour : 27/04/2024
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
    int inputPinUsed;
    int UniteUsed;

private:

    static const int DEFAUTLT_PIN;

    static const float TEMPERATURE_ERREUR;
    static const float HUMIDITE_ERREUR;

    DHT *dht;
    int typeSensorUsed;

    float lastTemperatureRead;
    float lastHumidityRead;
};
#endif