#include "MyProjectButton.h"

const int MyProjectButton::DEFAUTLT_NO_PIN_LED = -1;

MyProjectButton::MyProjectButton(int _buttonPinUsed)
{
    buttonPinUsed = _buttonPinUsed;
    ledPinUsed = DEFAUTLT_NO_PIN_LED;
}

MyProjectButton::~MyProjectButton()
{
}

bool MyProjectButton::init()
{
    // Configuration du pin en entrée pullup
    pinMode(buttonPinUsed, INPUT_PULLUP);

    return true;
}

bool MyProjectButton::readButton()
{
    buttonState = digitalRead(buttonPinUsed);
    if (buttonState == LOW && !isPressed)
    {
        if(ledPinUsed != -1)
        {
            digitalWrite(ledPinUsed, HIGH);
        }
        isPressed = true;
        return true;
    }
    else if (buttonState == HIGH)
    {
        isPressed = false;
        if(ledPinUsed != -1)
        {
            digitalWrite(ledPinUsed, LOW);
        }
    }
    return false;
}

bool MyProjectButton::setButtonLed(int pinLedToUsed)
{
        ledPinUsed = pinLedToUsed;
        pinMode(pinLedToUsed, OUTPUT);
        return true; 
}
 