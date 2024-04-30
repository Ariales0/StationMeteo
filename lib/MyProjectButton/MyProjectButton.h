/**
 * Classe de gestion d'un bouton et sa led liée s'il y en a une.
 *
 * @file MyProjectButton.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe MyProjectButton
 * @version 1.1.2
 * @date Création : 10/04/2024
 * @date Dernière mise à jour : 29/04/2024
 */
#ifndef MYPROJECTBUTTON_H
#define MYPROJECTBUTTON_H

#include <Arduino.h>

class MyProjectButton
{
public:
    MyProjectButton(int _buttonPinUsed);
    ~MyProjectButton();
    bool init();
    bool readButton();
    bool setButtonLed(int _pinLed);

private:

    int buttonPinUsed;
    int buttonState;
    bool isPressed;

    int ledPinUsed;
    static const int DEFAUTLT_NO_PIN_LED;
};

#endif
