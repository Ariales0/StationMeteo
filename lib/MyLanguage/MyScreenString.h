#ifndef MYSCREENSTRING_H
#define MYSCREENSTRING_H
#include "Enums.h"

class MyScreenString 
{
public:
    MyScreenString();
    ~MyScreenString();
    void setLanguageUsed(LANGUAGE language);
    const char* getMessage(MESSAGE_KEYS key);
    LANGUAGE getCurrentLanguage();

private:
    LANGUAGE currentLanguage;
    const char* MESSAGES[MESSAGES_NUMBER][LANGUAGES_NUMBER];
};

#endif
