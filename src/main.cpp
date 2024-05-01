/**
 * Fichier principal @file main.cpp
 *
 * Fonction setup()
 * Fonction loop()
 * Méthode lectureBoutons()
 * Méthode lectureMyTemp()
 *
 * @author Lecourt Quentin
 * @version 2.1
 * @date 28/04/2024
 */

#pragma region DEFINITIONS

/*-----------INCLUSIONS-----------*/
#include <Arduino.h>
// --- Classes de lib
#include "MyOledExtend.h"
#include "MyTemp.h"
#include "LanguageMessageManager.h"
#include "MyProjectButton.h"

#include "Enums.cpp"
#include "ImagesBMP.cpp"

// #define MYTEMP_MOCK
#ifdef MYTEMP_MOCK
#define MyTempImplementation MyTempMock
#include "MyTempMock.h"
#else
#define MyTempImplementation MyTemp
#endif

// Section Serial
#define SERIAL_SPEED 9600
#define SERIAL_DELAY 100

// Section de l'écran OLED (Dimensions, broche de réinitialisation, broche des données...)
#define SCREEN_WIDTH 128 // Largeur de l'écran OLED en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED en pixels
#define OLED_RESET 0     // Pin RESET pour l'ecran Oled

// Section de la broche et du type de capteur DTH
#define DHTPIN 32
#define DHTTYPE DHT22

// Broches des boutons utilisées
#define BROCHE_BOUTON_BLEU 26
#define BROCHE_BOUTON_VERT 27
#define BROCHE_BOUTON_JAUNE 14

// Broches des leds utilisées
#define BROCHE_LED_BLEU 18
#define BROCHE_LED_VERT 17
#define BROCHE_LED_JAUNE 16

/*-----------OBJETS-----------*/
MyOledExtend *myOledExtend = NULL;
MyTempImplementation *myTemp = NULL;
LanguageMessageManager *languageMessageManager = NULL;
MyProjectButton *boutonBleu = NULL;
MyProjectButton *boutonVert = NULL;
MyProjectButton *boutonJaune = NULL;

/*-----------CONSTANTES-----------*/
// --- Temperature d'erreur revoyé par MyTemp si aucune valeur obtenue
const float TEMPERATURE_ERREUR = -1000;
const float HUMIDITE_ERREUR = -1;

/*-----------VARIABLES-----------*/
bool humiditySurEcran = false;               // Etat de l'affichage de l'humidité.
LANGUAGE langueUtilisee = FRENCH;            // Langue d'affichage.
UNITY_TEMP uniteTempUtilise = UNITY_CELSIUS; // Unité de la température.
MESSAGE_KEYS unityMessage = CELSIUS;         // Unité de la température affichée.
// Variables des dernières données obtenu
float derniereTemperature = 0;
float derniereHumidite = 0;

// Sert à actualiser l'affichage lors de l'appui d'un bouton
bool actualiserAffichage = false;

/*-----------DÉLAIS ET DIVISEURS-----------*/
//  Les délais sont en millisecondes
const int DELAI_MY_OLED = 100;             // Délai accordé à l'objet myOled pour réagir.
const int DELAI_MY_TEMP = 2000;            // Le DHT22 a un temps de rafraîchissement de 2 secondes.
const int DELAI_LOOP = 10;                 // Loop toutes les 10 ms réagir rapidement à la pression des boutons.
const int DISPLAY_SPLASH_TIME = 1000;      // Temps en millisecondes pour l'initialisation de MyOled
const int DELAY_LED_INITIALISATION = 1000; // Temps pour lequel les leds reste allumees en millisecondes

// On appelle les méthodes de MyTemp (DELAI_MY_TEMP / DELAI_LOOP) fois par loop. Ainsi, on peut lire rapidement les boutons et lire les données du DTH22 toutes les 2s.
const int DIVIEUR_MYTEMP_LOOP = DELAI_MY_TEMP / DELAI_LOOP;
int decompteMyTempLoop = -1; // Permet de lire la temperature a la premiere boucle

#pragma endregion DEFINITIONS
#pragma region METHODES

/**
 * lectureMyTemp()
 *
 * @date Mise à jour : 30/04/2024
 * Ajustement avec MyOledExtend
 * 
 * @brief Méthode appelée dans la boucle principale pour afficher la température ou l'humidité sur l'écran OLED.
 * L'humidité ou la temprérature est lue.
 * Si la valeur est différente de la dernière valeur obtenue ou si l'affichage est à actualiser on affiche sur l'écran OLED.
 */
void lectureMyTemp()
{

  float temperatureObtenue = derniereTemperature;
  float humiditeObtenue = derniereHumidite;
  float valeurObtenue = (humiditySurEcran) ? humiditeObtenue = myTemp->getHumidity() : temperatureObtenue = myTemp->getTemperature();
  if ((valeurObtenue != HUMIDITE_ERREUR) && (valeurObtenue != TEMPERATURE_ERREUR))
  {
    if (humiditeObtenue != derniereHumidite || temperatureObtenue != derniereTemperature || actualiserAffichage)
    {
      const char *UNITE_VALEUR;
      const unsigned char *IMAGE;
      myOledExtend->rechargerEcran(languageMessageManager->getMessage(METEO_STATION));
      myOledExtend->afficherValeur(valeurObtenue);

      if (humiditySurEcran)
      {
        UNITE_VALEUR = languageMessageManager->getMessage(HUMIDITY);
        IMAGE = goutteEauHumiditeBMP_IMAGE;
        derniereHumidite = humiditeObtenue;
      }
      else
      {
        UNITE_VALEUR = languageMessageManager->getMessage(unityMessage);
        IMAGE = thermometreBMP_IMAGE;
        derniereTemperature = temperatureObtenue;
      }

      myOledExtend->afficherTitre(UNITE_VALEUR);
      myOledExtend->afficherImageBMP128x64(IMAGE);
      actualiserAffichage = false;
    }
  }
  else
  {
    myOledExtend->rechargerEcran(languageMessageManager->getMessage(METEO_STATION));
    myOledExtend->afficherSousTitre(languageMessageManager->getMessage(DHT22_ERROR));
    myOledExtend->afficherErreur(languageMessageManager->getMessage(READING_ERROR));
  }
}


/**
 * lectureBoutons()
 *
 * @date Mise à jour : 30/04/2024
 * Ajustement avec MyOledExtend
 * 
 * @brief Lit l'état des boutons et effectue les actions associées.
 */
void lectureBoutons()
{
  /*-----------LECTURE BOUTON BLEU-----------*/
  // Permet de changer le unité de la température entre Celsius et Fahrenheit.
  if (boutonBleu->readButton())
  {
    uniteTempUtilise = (uniteTempUtilise == UNITY_CELSIUS) ? UNITY_FAHRENHEIT : UNITY_CELSIUS;
    unityMessage = (uniteTempUtilise == UNITY_CELSIUS) ? CELSIUS : FAHRENHEIT;

    myTemp->setUniteUsed(uniteTempUtilise);
    actualiserAffichage = true;
    lectureMyTemp();
  }
  /*-----------LECTURE BOUTON VERT-----------*/
  // Permet de changer l'affichage entre Température et Humidité.
  if (boutonVert->readButton())
  {
    humiditySurEcran = !humiditySurEcran;
    actualiserAffichage = true;
    lectureMyTemp();
  }

  /*-----------LECTURE BOUTON JAUNE-----------*/
  // Permet de changer la langue d'affichage.
  if (boutonJaune->readButton())
  {
    langueUtilisee = (langueUtilisee == FRENCH) ? ENGLISH : FRENCH;

    languageMessageManager->setLanguageUsed(langueUtilisee);
    actualiserAffichage = true;
    lectureMyTemp();
  }
}

#pragma endregion METHODES
#pragma region FONCTIONS

/**
 * Fonction setup()
 *
 * @date Mise à jour : 30/04/2024
 * Ajustement avec MyOledExtend
 * 
 * @brief Initialise le programme en configurant les éléments nécessaires au démarrage.
 */
void setup()
{
  Serial.begin(SERIAL_SPEED);
  delay(SERIAL_DELAY);

  /*-----------MyScreenString-----------*/
  languageMessageManager = new LanguageMessageManager();
  while (!languageMessageManager);
  languageMessageManager->setLanguageUsed(langueUtilisee);

  /*---------------MyOled---------------*/
  myOledExtend = new MyOledExtend(&Wire, OLED_RESET, SCREEN_HEIGHT, SCREEN_WIDTH);
  while (!myOledExtend);
  while (myOledExtend->init(DISPLAY_SPLASH_TIME) == 1);
  delay(DELAI_MY_OLED);
  myOledExtend->rechargerEcran(languageMessageManager->getMessage(METEO_STATION));

  /*---------------MyTemp---------------*/
  myTemp = new MyTempImplementation();
  while (!myTemp)
  {
    myOledExtend->afficherTitre(languageMessageManager->getMessage(INSTANTIATION));
    myOledExtend->afficherSousTitre(languageMessageManager->getMessage(DHT22_ERROR));
  }
  while (!myTemp->init(DHTPIN, DHTTYPE))
  {
    myOledExtend->afficherTitre(languageMessageManager->getMessage(INITIALISATION));
    myOledExtend->afficherSousTitre(languageMessageManager->getMessage(DHT22_ERROR));
    myOledExtend->afficherErreur(languageMessageManager->getMessage(PIN_PROBLEM));
  }
  myTemp->setUniteUsed(uniteTempUtilise);

  /*-----------MyProjectButton----------*/
  // Bouton bleu - Permet de changer le unité de la température entre Celsius et Fahrenheit.
  boutonBleu = new MyProjectButton(BROCHE_BOUTON_BLEU);
  // Bouton vert - Permet de changer l'affichage entre Température et Humidité.
  boutonVert = new MyProjectButton(BROCHE_BOUTON_VERT);
  // Bouton jaune - Permets de changer la langue d'affichage.
  boutonJaune = new MyProjectButton(BROCHE_BOUTON_JAUNE);

  while (!boutonBleu || !boutonVert || !boutonJaune)
  {
    myOledExtend->afficherTitre(languageMessageManager->getMessage(INSTANTIATION));
    myOledExtend->afficherSousTitre(languageMessageManager->getMessage(DHT22_ERROR));
  }
  while (!boutonBleu->init() || !boutonVert->init() || !boutonJaune->init())
  {
    myOledExtend->afficherTitre(languageMessageManager->getMessage(INITIALISATION));
    myOledExtend->afficherSousTitre(languageMessageManager->getMessage(BUTTON_ERROR));
  }
  // Faire le lien entre une led et son bouton
  boutonBleu->setButtonLed(BROCHE_LED_BLEU);
  boutonVert->setButtonLed(BROCHE_LED_VERT);
  boutonJaune->setButtonLed(BROCHE_LED_JAUNE);
  delay(DELAY_LED_INITIALISATION);
}

/**
 * Fonction loop()
 *
 * @brief Boucle principale de l'ESP32, interrogeant périodiquement les méthodes nécessaires.
 */
void loop()
{
  lectureBoutons();

  if (decompteMyTempLoop < 0)
  {
    decompteMyTempLoop = DIVIEUR_MYTEMP_LOOP;
    lectureMyTemp();
  }

  delay(DELAI_LOOP);
  --decompteMyTempLoop;
}
#pragma endregion FONCTIONS