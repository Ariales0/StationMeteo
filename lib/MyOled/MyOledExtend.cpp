/**
 * Implémentation des méthodes de l'extension MyOledExtend.
 * @file MyOledExtend.cpp
 * @author Lecourt Quentin
 * @brief Méthodes de la classe MyOledExtend
 * @version 1.1.1
 * @date Création : 30/04/24
 * @date Dernière mise à jour : 30/04/2024
*/
#include "MyOledExtend.h"

/**
 * 
 * Constructeur de MyOledExtend.
 * @param twi Pointeur vers l'objet TwoWire pour la communication I2C.
 * @param RST Broche de réinitialisation de l'écran OLED.
 * @param rawHeight Hauteur de l'écran OLED.
 * @param rawWidth Largeur de l'écran OLED.
*/
MyOledExtend::MyOledExtend(TwoWire *twi, uint8_t RST, uint8_t rawHeight, uint8_t rawWidth) : MyOled(twi, RST, rawHeight, rawWidth)
{
    screenWidth = rawWidth;
    screenHeight = rawHeight;
}
/**
 * 
 * Destructeur de MyOledExtend.
*/
MyOledExtend::~MyOledExtend()
{
    clearDisplay();
}
/**
 * 
 * Recharge l'écran OLED avec un nouveau titre.
 * @param EN_TETE Titre à afficher.
*/
void MyOledExtend::rechargerEcran(const char *EN_TETE)
{
    clearDisplay();
    setTextSize(1);
    printIt(POSITION_X_EN_TETE, POSITION_Y_EN_TETE, EN_TETE, true);
}
/**
 * 
 * Affiche une valeur numérique sur l'écran OLED.
 * @param value Valeur à afficher.
*/
void MyOledExtend::afficherValeur(float value)
{
    char valeurSTR[7];
    sprintf(valeurSTR, "%.2f", value);
    setTextSize(2);
    printIt(POSITION_X_VALUE, POSITION_Y_VALUE, valeurSTR, true);
    setTextSize(1);
}
/**
 * 
 * Affiche un titre sur l'écran OLED.
 * @param TITRE Titre à afficher.
*/
void MyOledExtend::afficherTitre(const char *TITRE)
{
    printIt(positionX_Centre(TITRE), POSITION_Y_TITRE, TITRE, true);
}
/**
 * 
 * Affiche un sous-titre sur l'écran OLED.
 * @param SOUS_TITRE Sous-titre à afficher.
*/
void MyOledExtend::afficherSousTitre(const char *SOUS_TITRE)
{
    printIt(positionX_Centre(SOUS_TITRE), POSITION_Y_SOUS_TITRE, SOUS_TITRE, true);
}
/**
 * 
 * Affiche un message d'erreur détaillé sur l'écran OLED.
 * @param ERREUR_DETAILS Détails de l'erreur à afficher.
*/
void MyOledExtend::afficherErreur(const char *ERREUR_DETAILS)
{
    printIt(positionX_Centre(ERREUR_DETAILS), POSITION_Y_ERROR_DETAIL, ERREUR_DETAILS, true);
}
/**
 * 
 * Affiche un message flexible à une position spécifique sur l'écran OLED.
 * @param MESSAGE_FLEXIBLE Message flexible à afficher.
 * @param positionX Position horizontale du message.
 * @param positionY Position verticale du message.
*/
void MyOledExtend::afficherMessageFlexible(const char *MESSAGE_FLEXIBLE, int positionX, int positionY)
{
    printIt(positionX, positionY, MESSAGE_FLEXIBLE, true);
}
/**
 * 
 * Affiche une image BMP de taille 128x64 sur l'écran OLED.
 * @param IMAGE_BMP Image BMP à afficher.
*/
void MyOledExtend::afficherImageBMP128x64(const unsigned char *IMAGE_BMP)
{
    drawBitmap(0, 0, IMAGE_BMP, screenWidth, screenHeight, WHITE);
    display();
}
/**
 * 
 * Affiche une image BMP flexible à une position spécifique sur l'écran OLED.
 * @param IMAGE_BMP Image BMP à afficher.
 * @param positionX Position horizontale de l'image.
 * @param positionY Position verticale de l'image.
 * */
void MyOledExtend::afficherImageBMPFlexible(const unsigned char *IMAGE_BMP, int positionX, int positionY)
{
    drawBitmap(positionX, positionY, IMAGE_BMP, screenWidth, screenHeight, WHITE);
    display();
}
/**
 * 
 * Retourne un position x de façon à centrer le message
 * @param MESSAGE Message à centrer.
 * @return positionDynamiqueX Entier qui correspond à la position X du message pour centrer ce dernier
 * */
int MyOledExtend::positionX_Centre(const char *MESSAGE)
{
    int longueurChaine = strlen(MESSAGE);
    int positionDynamiqueX = (screenWidth - (longueurChaine * 5)) / 3;
    return positionDynamiqueX;
}