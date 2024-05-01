/**
 * Classe hérité de la classe MyOled, complementation
 * Des méthodes supplémentaires sont ajoutées
 * @file MyOledExtend.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe MyOledExtend
 * @version 1.1.1
 * @date Création : 30/04/2024
 * @date Dernière mise à jour : 30/04/2024
 */
#ifndef MYOLEDEXTEND_H
#define MYOLEDEXTEND_H

#include "MyOled.h"
class MyOledExtend : public MyOled
{
public:
    MyOledExtend(TwoWire *twi, uint8_t RST, uint8_t rawHeight, uint8_t rawWidth);
    ~MyOledExtend();
    
    void rechargerEcran(const char *EN_TETE);
    void afficherValeur(float value);
    void afficherTitre(const char *TITRE);
    void afficherSousTitre(const char *SOUS_TITRE);
    void afficherErreur(const char *ERREUR_DETAILS);
    void afficherMessageFlexible(const char *MESSAGE_FLEXIBLE, int positionX, int positionY);

    void afficherImageBMP128x64(const unsigned char *IMAGE_BMP);
    void afficherImageBMPFlexible(const unsigned char *IMAGE_BMP, int positionX, int positionY);

private:
    int positionX_Centre(const char *MESSAGE);

    static const uint8_t DEFAULT_SCREEN_WIDTH = 128;
    static const uint8_t DEFAULT_SCREEN_HEIGHT = 64;
    static const uint8_t DEFAULT_SCREEN_RESET = 4;
    int screenWidth;
    int screenHeight;

    static const int POSITION_X_EN_TETE = 1;
    static const int POSITION_Y_EN_TETE = 2;
    static const int POSITION_Y_TITRE = 20;
    static const int POSITION_Y_SOUS_TITRE = 35;
    static const int POSITION_Y_ERREUR_DETAIL = 50;
    static const int POSITION_X_VALUE = 23;
    static const int POSITION_Y_VALUE = 38;
};
#endif