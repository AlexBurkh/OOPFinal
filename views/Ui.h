#pragma once

#include <iostream>
#include <string>
#include "View.h"
#include "ConsoleView.h"

class Ui
{
    public:
        Ui(View* v);
        virtual void Start();
    private:
        View* V;
        bool flag = true;

        virtual std::string GlobalMenu();
        virtual std::string FinanceStorageCreationMenu();
        virtual std::string FinanceStorageFindMenu();
        virtual std::string FinanceStorageDeleteMenu();

        void GlobalMenuPointHandler(const char& point);
};