#pragma once
#include "View.h"

class ConsoleView : public View
{
    public:
        ConsoleView();
        void Display(std::string textToDisplay) override;
        std::string ReadLine() override;
        char Read() override;
};