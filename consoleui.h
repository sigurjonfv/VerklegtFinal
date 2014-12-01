#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services.h"
#include "stdlib.h"

class ConsoleUI
{
    public:
        void ShowMainMenu();
        int SwitchMainMenu();
        void ShowSearchMenu();
        void SwitchSearchMenu();
        ConsoleUI();
        void start();
        void end();
    protected:
        Services s;
    private:
};

#endif // CONSOLEUI_H
