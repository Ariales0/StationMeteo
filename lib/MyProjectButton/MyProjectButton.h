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
