/**
 * Gestion d'un capteur de température DHT
 *
 * @file MyTemp.cpp
 * @author Lecourt Quentin
 * @brief Methode de la classe MyTemp
 * @version 1.2.2
 * @date Création : 02/03/24
 * @date Dernière mise à jour : 29/04/2024
 */
#include "MyTemp.h"

/**
 * MyTemp Constructeur de la classe MyTemp
 *
 * Appelle la méthode setUniteUsed pour initialiser UNITY_TEMP à FAHRENHEIT
 */
MyTemp::MyTemp()
{
    setUniteUsed(UNITY_FAHRENHEIT);
}

/**
 * init Initialise la classe MyTemp.
 * Initialise les attributs inputPinUsed, typeSensorUsed, lastTemeratureRead, lastHumidityRead.
 * Alloue dynamiquement l'objet DHT et gestion des erreurs.
 * 
 * @date Dernière mise à jour : 29/04/2024
 * @brief Initialisation des dernieres valeurs par les valeurs d'erreur
 * 
 *
 * @param int _inputPinUsed Pin alloué aux données du capteur, valeur par défaut = DEFAUTLT_PIN
 * @param int _typeSensorUsed Type de capteur DHT (DHT11, DHT22...)
 * @return true si l'initialisation est réussie, false sinon
 */
bool MyTemp::init(int _inputPinUsed = DEFAUTLT_PIN, int _typeSensorUsed = DHT22)
{

    inputPinUsed = _inputPinUsed;
    typeSensorUsed = _typeSensorUsed;

    lastTemperatureRead = TEMPERATURE_ERREUR;
    lastHumidityRead = HUMIDITE_ERREUR;
    
    dht = new DHT(inputPinUsed, typeSensorUsed);
    if (!dht)
    {
        return false;
    }
    dht->begin();
    return !isnan(dht->readTemperature()); // Retourne true si dht est bien instancié, sinon false
}

/**
 * Mutateur setUniteUsed
 * Initialise l'attribut UniteUsed avec l'unité de température à afficher.
 *
 * @param UNITY_TEMP uniteUsed Unité de température à afficher, valeur par défaut = UNITY_FARHENHEIT
 * @return true si l'unité est valide et a été définie avec succès, false sinon
 */
bool MyTemp::setUniteUsed(UNITY_TEMP uniteUsed)
{
    if (uniteUsed == UNITY_CELSIUS || uniteUsed == UNITY_FAHRENHEIT)
    {
        UniteUsed = uniteUsed;
        return true;
    }
    return false;
}

/**
 * Accesseur getTemperature
 * Récupère la température captée par le capteur et la retourne en fonction de l'unité de température utilisée.
 * Gestion des erreurs.
 * 
 * @date Dernière mise à jour : 27/04/2024
 * @brief On retourne la température d'erreur si le capteur n'est parvenu à lire de valeur
 * 
 * @return La température dans l'unité utilisée (Celsius ou Fahrenheit)
 */
float MyTemp::getTemperature()
{
    float temperature = dht->readTemperature(UniteUsed);
    if (!isnan(temperature))
    {
        lastTemperatureRead = temperature;
    }
    else
    {
        lastTemperatureRead = TEMPERATURE_ERREUR;
    }
    return lastTemperatureRead;
}

/**
 * Accesseur getHumidity
 * Récupère l'humidité captée par le capteuret la retourne.
 * Gestion des erreurs.
 *
 * @date Dernière mise à jour : 27/04/2024
 * @brief On retourne l'humidité d'erreur si le capteur n'est parvenu à lire de valeur
 * 
 * @return L'humidité relative en pourcentage
 */
float MyTemp::getHumidity()
{
    float humidite = dht->readHumidity();
    if (!isnan(humidite))
    {
        lastHumidityRead = humidite;
    }
    else
    {
        lastHumidityRead = HUMIDITE_ERREUR;
    }
    return lastHumidityRead;
}