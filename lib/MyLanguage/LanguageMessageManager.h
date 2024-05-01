/**
 * Classe de gestion des languages et leures messages
 *
 * @file LanguageMessageManager.h
 * @author Lecourt Quentin
 * @brief Declaration de la classe LanguageMessageManager
 * @version 1.1
 * @date Création : 23/04/2024
 * @date Dernière mise à jour : 29/04/2024
 */
#ifndef LANGUAGEMESSAGEMANAGER_H
#define LANGUAGEMESSAGEMANAGER_H

#include "Enums.cpp"

class LanguageMessageManager
{
public:
    LanguageMessageManager();
    bool setLanguageUsed(LANGUAGE language);
    const char* getMessage(MESSAGE_KEYS key);

private:
    LANGUAGE currentLanguage;
    const char* MESSAGES[MESSAGES_NUMBER][LANGUAGES_NUMBER];
};

#endif
