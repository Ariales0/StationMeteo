/**
 * Gestion des langues et leures messages
 *
 * @file LanguageMessageManager.cpp
 * @author Lecourt Quentin
 * @brief Methode de la classe LanguageMessageManager
 * @version 1.2
 * @date Création : 23/04/24
 * @date Dernière mise à jour : 27/04/2024
 */
#include "LanguageMessageManager.h"
/**
 * Constructeur de la classe
*/
LanguageMessageManager::LanguageMessageManager() 
{
    
    setLanguageUsed(FRENCH);

    // Initialisation des messages en français et en anglais pour l'ecran l'affichage
    MESSAGES[METEO_STATION][FRENCH] = "Station Méteo";
    MESSAGES[METEO_STATION][ENGLISH] = "Weather Channel";

    MESSAGES[DHT22_ERROR][FRENCH] = "DHT22:ERREUR";
    MESSAGES[DHT22_ERROR][ENGLISH] = "DHT22:ERROR";

    MESSAGES[INSTANTIATION][FRENCH] = "Instanciation";
    MESSAGES[INSTANTIATION][ENGLISH] = "Instanciation";

    MESSAGES[INITIALISATION][FRENCH] = "Initialisation";
    MESSAGES[INITIALISATION][ENGLISH] = "Initialisation";

    MESSAGES[PIN_PROBLEM][FRENCH] = "Verifiez la broche";
    MESSAGES[PIN_PROBLEM][ENGLISH] = "Maybe Bad Pin USED";

    MESSAGES[CELSIUS][FRENCH] = "Celsius";
    MESSAGES[CELSIUS][ENGLISH] = "Celsius";

    MESSAGES[FAHRENHEIT][FRENCH] = "Farhenheit";
    MESSAGES[FAHRENHEIT][ENGLISH] = "Farhenheit";

    MESSAGES[HUMIDITY][FRENCH] = "Humidite";
    MESSAGES[HUMIDITY][ENGLISH] = "Humidity";

    MESSAGES[BUTTON_ERROR][FRENCH] = "BOUTON:ERREUR";
    MESSAGES[BUTTON_ERROR][ENGLISH] = "BUTTON:ERROR";

    MESSAGES[READING_ERROR][FRENCH] = "Erreur de lecture";
    MESSAGES[READING_ERROR][ENGLISH] = "Reading error";
}
/**
 * Accesseur getMessage
 * 
 * @brief Permet d'obtenir un message à partir de sa clé
 * 
 * @param key Clé du message à retourner
 * @return MESSAGES Le message en fonction de la clè et de la langue
*/
const char* LanguageMessageManager::getMessage(MESSAGE_KEYS key) 
{
    return MESSAGES[key][currentLanguage];
}
/**
 * Mutateur setLanguage
 * 
 * @brief Permet de choisir la langue utiliée
*/
void LanguageMessageManager::setLanguageUsed(LANGUAGE language) 
{
    currentLanguage = language;
}



