/**
 * Gestion des boutons et leurs potentiels leds
 *
 * @file MyProjectButton.cpp
 * @author Lecourt Quentin
 * @brief Methode de la classe MyProjectButton
 * @version 1.1.3
 * @date Création : 10/04/24
 * @date Dernière mise à jour : 29/04/2024
 */
#include "MyProjectButton.h"

const int MyProjectButton::DEFAUTLT_NO_PIN_LED = -1;

/**
 * Constructeur de la classe
 * 
 * @param _buttonPinUsed Le numero de broche du bouton
 * 
 */
MyProjectButton::MyProjectButton(int _buttonPinUsed)
{
    buttonPinUsed = _buttonPinUsed;
    ledPinUsed = DEFAUTLT_NO_PIN_LED;
}

/**
 * Destructeur de la classe
 */
MyProjectButton::~MyProjectButton()
{
}


/**
 * Initialisation init
 * Initialise la classe et configuration du pin en entrée pullup
 * 
 * @return true
 */
bool MyProjectButton::init()
{
    pinMode(buttonPinUsed, INPUT_PULLUP);

    return true;
}


/**
 * Methode readButton
 * Lecture de l'etat du bonton
 * Si bouton appuye, alors la led s'allu;e si il y a une led
 * 
 * @date Dernière mise à jour : 29/04/2024
 * @brief Adaptation de la methode avec une possible led
 * 
 * @return L'etat du bouton, appuye(true) sinon (false)
 */
bool MyProjectButton::readButton()
{
    buttonState = digitalRead(buttonPinUsed);
    if (buttonState == LOW && !isPressed)
    {
        if(ledPinUsed != DEFAUTLT_NO_PIN_LED)
        {
            digitalWrite(ledPinUsed, HIGH);
        }
        isPressed = true;
        return true;
    }
    else if (buttonState == HIGH)
    {
        isPressed = false;
        if(ledPinUsed != DEFAUTLT_NO_PIN_LED)
        {
            digitalWrite(ledPinUsed, LOW);
        }
    }
    return false;
}


/**
 * Mutateur setButtonLed
 * Agremente l'attribut ledPinUsed avec le numero de broche de la led
 * Configuration de la pin
 * 
 * @date Creation : 29/04/2024
 * @param pinLedToUsed Le numero de la broche de la led pour un bouton
 * 
 * @return true
 */
bool MyProjectButton::setButtonLed(int pinLedToUsed)
{
        ledPinUsed = pinLedToUsed;
        pinMode(pinLedToUsed, OUTPUT);
        digitalWrite(ledPinUsed, HIGH);
        return true; 
}
 