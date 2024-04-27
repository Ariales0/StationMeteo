#include "MyProjectButton.h"

MyProjectButton::MyProjectButton(int _buttonPinUsed)
{
    buttonPinUsed = _buttonPinUsed;
}

MyProjectButton::~MyProjectButton()
{
}

bool MyProjectButton::init()
{
    buttonState = 0;
    isPressed = false;
    // Configuration du pin en entrée pullup
    pinMode(buttonPinUsed, INPUT_PULLUP);

    return true;
}

bool MyProjectButton::readButton()
{
    buttonState = digitalRead(buttonPinUsed);

    if (buttonState == LOW && !isPressed)
    {
        Serial.println("Bouton bleu");
        isPressed = true;
        return true;
    }
    else if (buttonState == HIGH)
    {
        isPressed = false;
    }
    return false;
}

 