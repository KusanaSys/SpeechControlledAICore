// SpeechControlledAICore.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CLogger.h"

string printSelectionMenu()
{
    char cChoix = ' ';
    string sCommand;

    system("cls");

    std::cout << "Que souhaitez-vous faire ?" << std::endl
        << "  1. Ajouter un rendez-vous dans l'agenda..." << std::endl
        << "  2. Donne-moi la météo..." << std::endl
        << "  3. Ouvre-moi un logiciel..." << std::endl << std::endl
        << "Votre choix : " << std::flush;
    std::cin >> cChoix;

    switch (cChoix)
    {
        case '1':
            sCommand = "Lancement du processus Ajout Agenda";
            break;
        case '2':
            sCommand = "Lancement du processus Météo";
            break;
        case '3':
            sCommand = "Lancement du processus Ouverture Logiciel";
            break;
        default:
            sCommand = "Input incorrecte, terminaison du process d'écoute...";
            break;
    }

    std::cout << sCommand << std::endl << std::flush;
    return sCommand;
}

int main()
{
    CLogger o_MainLog("mainLog");
    
    o_MainLog.log(printSelectionMenu());
}
