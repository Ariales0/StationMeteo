#ifndef LANGUAGEMESSAGEMANAGER_H
#define LANGUAGEMESSAGEMANAGER_H

#include "Enums.cpp"

class LanguageMessageManager
{
public:
    LanguageMessageManager();
    ~LanguageMessageManager();
    void setLanguageUsed(LANGUAGE language);
    const char* getMessage(MESSAGE_KEYS key);
    LANGUAGE getCurrentLanguage();

private:
    LANGUAGE currentLanguage;
    const char* MESSAGES[MESSAGES_NUMBER][LANGUAGES_NUMBER];
};

#endif
