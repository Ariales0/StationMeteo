#ifndef MYPROJECTBUTTON_H
#define MYPROJECTBUTTON_H

#include "MyOled.h"
#include "MyTemp.h"
#include "MyScreenString.h"
#include "Enums.h"

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
