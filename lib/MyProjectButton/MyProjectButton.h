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

private:

    int buttonPinUsed;
    int buttonState;
    bool isPressed;
};

#endif
