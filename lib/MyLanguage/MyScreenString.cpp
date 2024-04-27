#include "MyScreenString.h"

MyScreenString::MyScreenString() 
{
    
    currentLanguage=FRENCH;

    // Initialisation des messages en français et en anglais pour l'ecran l'affichage
    MESSAGES[METEO_STATION][FRENCH] = "Station Meteo";
    MESSAGES[METEO_STATION][ENGLISH] = "Meteo Station";

    MESSAGES[DHT22_ERROR][FRENCH] = "DHT22:ERREUR";
    MESSAGES[DHT22_ERROR][ENGLISH] = "DHT22:ERROR";

    MESSAGES[INSTANTIATION][FRENCH] = "Instanciation";
    MESSAGES[INSTANTIATION][ENGLISH] = "Instanciation";

    MESSAGES[INITIALISATION][FRENCH] = "Initialisation";
    MESSAGES[INITIALISATION][ENGLISH] = "Initialisation";

    MESSAGES[PIN_PROBLEM][FRENCH] = "Verifiez la broche utilise";
    MESSAGES[PIN_PROBLEM][ENGLISH] = "Maybe Bad Pin USED";

    MESSAGES[CELSIUS][FRENCH] = "cel";
    MESSAGES[CELSIUS][ENGLISH] = "cel";

    MESSAGES[FAHRENHEIT][FRENCH] = "far";
    MESSAGES[FAHRENHEIT][ENGLISH] = "far";

    MESSAGES[HUMIDITY][FRENCH] = "Humidite";
    MESSAGES[HUMIDITY][ENGLISH] = "Humidity";

    MESSAGES[BUTTON_ERROR][FRENCH] = "BOUTON:ERREUR";
    MESSAGES[BUTTON_ERROR][ENGLISH] = "BUTTON:ERROR";

    MESSAGES[READING_ERROR][FRENCH] = "Erreur de lecture";
    MESSAGES[READING_ERROR][ENGLISH] = "Reading error";
}

MyScreenString::~MyScreenString() {}

void MyScreenString::setLanguageUsed(LANGUAGE language) 
{
    currentLanguage = language;
}

LANGUAGE MyScreenString::getCurrentLanguage()
{
    return currentLanguage;
}

const char* MyScreenString::getMessage(MESSAGE_KEYS key) 
{
    return MESSAGES[key][currentLanguage];
}



