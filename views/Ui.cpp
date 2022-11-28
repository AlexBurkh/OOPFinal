#include "Ui.h"

Ui::Ui(View* v)
{
    this->V = v;
}

void Ui::Start()
{
    while(flag) {
        V->Display(GlobalMenu());
        V->Display("Выберите пункт меню > ");
        char point = V->Read();
        GlobalMenuPointHandler(point);
    }
}

std::string Ui::GlobalMenu()
{
    std::string result = "Добро пожаловать в программу управления вашими финансами\n";
    result += "1. Создать копилку\n";
    result += "2. Найти копилку\n";
    result += "3. Удалить копилку\n"; 
    result += "4. Выйти\n";
    return result;
}

std::string Ui::FinanceStorageCreationMenu()
{
    std::string result = "Создание копилки\n";
    result += "1. Создать банковскую карту\n";
    result += "2. Создать конверт\n";
    return result;
}

std::string Ui::FinanceStorageFindMenu()
{

}
std::string Ui::FinanceStorageDeleteMenu()
{

}

void Ui::GlobalMenuPointHandler(const char& point)
{
    switch (point) {
        case '1': {
            break;
        }
        case '2': {
            break;
        }  
        case '3': {
            break;
        } 
        case '4': {
            V->Display("До свидания!\n");
            flag = false;
            break;
        } 
        default: {
            break;
        }
    }
}   
