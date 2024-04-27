#ifndef ENUMS_H
#define ENUMS_H

// Enumération des langues disponibles
enum LANGUAGE {
    FRENCH,
    ENGLISH,
    LANGUAGES_NUMBER
};

// Enumération des clés de message possibles
enum MESSAGE_KEYS {
    METEO_STATION,
    DHT22_ERROR,
    INSTANTIATION,
    INITIALISATION,
    PIN_PROBLEM,
    CELSIUS,
    FAHRENHEIT,
    HUMIDITY,
    BUTTON_ERROR,
    READING_ERROR,
    MESSAGES_NUMBER
};

// Enumération des unités de température
enum UNITY_TEMP
{
    UNITY_CELSIUS,
    UNITY_FAHRENHEIT
};

#endif