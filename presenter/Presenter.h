#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "../views/ConsoleView.h"
#include "../views/View.h"
#include "../models/EFinanceStorageType.h"
#include "../models/FinanceStorage.h"
#include "../models/BankCard.h"
#include "../models/Envelope.h"

class Presenter
{
    public:
        Presenter(View*, std::vector<FinanceStorage*>*);
        ~Presenter();
        void Start();
    private:
        View* UI;
        std::vector<FinanceStorage*>* Storages;
        bool flag = true;

        // Пункты меню для вывода
        static std::string GlobalMenu();
        static std::string CreationMenu();
        static std::string FinanceStorageActionMenu(FinanceStorage*);
        std::string SelectionMenu();

        // Пункты меню выбора типа банковской карты
        static std::string CreateBankCardMenu();

        // ОБРАБОТКА МЕНЮ
        // Обработка главного меню
        void GlobalMenuHandler();
        void GlobalMenuPointHandler(const char&);

        // Обработка меню создания копилок
        void CreationMenuHandler();
        void CreationMenuPointHandler(const char&);

        // Обработка меню выбора копилок
        void SelectionMenuHandler();
        void SelectionMenuPointHandler(const char&);
        void FinanceStorageActionMenuPointHandler(const char&, int, FinanceStorage*);

        // Функции создания копилок
        // Общие
        std::string EnterName();
        std::string EnterComment();
        // Карты
        void CreateBankCard();
        EBankCardType EnterBankCardType(const char&);
        std::string EnterCardNumber();
        static bool ValidateNumber(const std::string&);
        // Конверты
        void CreateEnvelope();


        // Функции копилки
        void TransferHandler(FinanceStorage*, int);
        void RefillHandler(FinanceStorage*, int);
};