#include "Presenter.h"

Presenter::Presenter(View* ui, std::vector<FinanceStorage*>* storages)
{
    this->UI = ui;
    this->Storages = storages;
}
Presenter::~Presenter()
{
    delete(UI);
    delete(Storages);
}

void Presenter::Start()
{
    while(flag) {
        GlobalMenuHandler();
    }
}

// Пункты меню для вывода
std::string Presenter::GlobalMenu()
{
    std::string result = "Добро пожаловать в программу управления вашими финансами\n";
    result += "1. Создать копилку\n";
    result += "2. Выбрать копилку\n";
    result += "3. Выйти\n";
    return result;
}
std::string Presenter::CreationMenu()
{
    std::string result = "Создание копилки\n";
    result += "1. Создать банковскую карту\n";
    result += "2. Создать конверт\n";
    result += "3. Назад\n";
    return result;
}
std::string Presenter::SelectionMenu()
{
    std::string result = "Выбор копилки\n";
    for (size_t i = 0; i != Storages->size(); ++i)
    {
        result += (std::to_string(i) + ". " + Storages->at(i)->ToString());
    }
    return result;
}
std::string Presenter::FinanceStorageActionMenu(FinanceStorage* fs)
{
    std::string result = "Меню действий с копилкой " + fs->ToString();
    result += "1. Перевести в другую копилку\n";
    result += "2. Пополнить из другой копилки\n";
    result += "3. Пополнить\n";
    result += "4. Удалить копилку\n";
    result += "5. Назад\n";
    return result;
}

// Выбрать тип карты
std::string Presenter::CreateBankCardMenu()
{
    std::string result = "Выберите тип банковской карты\n";
    result += "1. Дебетовая карта\n";
    result += "2. Кредитная карта\n";
    result += "3. Назад\n";
    return result;
}

// Обработка главного меню
void Presenter::GlobalMenuHandler()
{
    UI->Display(GlobalMenu());
    UI->Display("Выберите пункт меню > ");
    GlobalMenuPointHandler(UI->Read());
}
void Presenter::GlobalMenuPointHandler(const char& point)
{
    switch (point) {
        case '1': {
            CreationMenuHandler();
            break;
        }
        case '2': {
            SelectionMenuHandler();
            break;
        }  
        case '3': {
            UI->Display("До свидания!\n");
            flag = false;
            break;
        } 
        default: {
            break;
        }
    }
}   


// СОЗДАНИЕ КОПИЛКИ
// Меню создания копилки
void Presenter::CreationMenuHandler()
{
    UI->Display(CreationMenu());
    UI->Display("Выберите пункт меню > ");
    CreationMenuPointHandler(UI->Read());
}
void Presenter::CreationMenuPointHandler(const char& point)
{
    switch (point)
    {
        case '1':
            CreateBankCard();
            break;
        case '2':
            CreateEnvelope();
            break;
        case '3':
            UI->Display("Возврат в предыдущее меню ...\n");
            break;
        default:
            break;
    }
}

// Создание карты
void Presenter::CreateBankCard()
{
    UI->Display(CreateBankCardMenu());
    UI->Display("Выберите тип карты > ");
    EBankCardType cardType = EnterBankCardType(UI->Read());
    std::string name = EnterName();
    std::string comment = EnterComment();
    std::string number = EnterCardNumber();
    auto* bc = new BankCard(cardType, number, name, comment, 0);
    Storages->push_back(bc);
    UI->Display("Создана карта " + bc->ToString());
}
EBankCardType Presenter::EnterBankCardType(const char& point)
{
    switch (point)
    {
        case '1':
            return EBankCardType::Debit;
            break;
        case '2':
            return EBankCardType::Credit;
            break;
        case '3':
            UI->Display("Возврат в предыдущее меню ...\n");
            break;
        default:
            return EBankCardType::Debit;
            break;
    }
}
std::string Presenter::EnterCardNumber()
{
    UI->Display("Введите номер карты: ");
    std::string number = UI->ReadLine();
    if (ValidateNumber(number)) {
        return number;
    }
    return "";
}
bool Presenter::ValidateNumber(const std::string& number)
{
    if (number.size() == 16) {
        for (const char s : number) {
            if (! isdigit(s)) {
                break;
            }
        }
        return true;
    }
    return false;
}

// Создание конверта
void Presenter::CreateEnvelope()
{
    UI->Display("Создание конверта\n");
    std::string name = EnterName();
    std::string comment = EnterComment();
    auto* e = new Envelope(name, comment, 0);
    Storages->push_back(e);
    UI->Display("Создан конверт " + e->ToString());
}

// Общие функции для создания копилок
std::string Presenter::EnterName()
{
    UI->Display("Введите имя копилки:\n");
    std::string name = UI->ReadLine();
    if (!name.empty()) {
        return name;
    }
    return "Копилка без имени";
}
std::string Presenter::EnterComment()
{
    UI->Display("Введите комментарий:\n");
    std::string comment = UI->ReadLine();
    if (!comment.empty()) {
        return comment;
    }
    return "";
}

// ВЫБОР КОПИЛКИ
void Presenter::SelectionMenuHandler()
{
    if (!Storages->empty()) {
        UI->Display(SelectionMenu());
        UI->Display("Выберите копилку > ");
        SelectionMenuPointHandler(UI->Read());
    } else {
        UI->Display("Еще не создано ни одной копилки\n");
    }
}
void Presenter::SelectionMenuPointHandler(const char& menuPoint)
{
    int index = -1;
    if (isdigit(menuPoint)) {
        index = menuPoint - '0';
    } 
    if ((index >= 0) && (index < Storages->size())) {
        FinanceStorage* fs = Storages->at(index);
        UI->Display(FinanceStorageActionMenu(fs));
        UI->Display("Выберите действие > ");
        FinanceStorageActionMenuPointHandler(UI->Read(), index, fs);
    }
}
void Presenter::FinanceStorageActionMenuPointHandler(const char& menuPoint, int currentStorageIndex, FinanceStorage* currentStorage)
{
    switch (menuPoint)
    {
    case '1':
        if (Storages->size() > 1) {
            TransferHandler(currentStorage, currentStorageIndex);
        } else {
            UI->Display("Нет копилок для перевода\n");
        }
        break;
    case '2':
        if (Storages->size() > 1) {
            RefillHandler(currentStorage, currentStorageIndex);
        } else {
            UI->Display("Нет копилок для перевода\n");
        }
        break;
    case '3':
        UI->Display("Введите сумму для пополнения");
        currentStorage->Add(std::stod(UI->ReadLine()));
        break;
    case '4':
        if (currentStorage->GetBalance() == 0) {
            UI->Display("Удаление копилки " + currentStorage->ToString());
            delete(currentStorage);
            Storages->erase(Storages->begin() + currentStorageIndex);
        }
        else {
            UI->Display("Невозможно удалить копилку пока на ней остались денежные средства\n");
        }
        break;
    case '5':
        UI->Display("Возврат в предыдущее меню ...");
        break;
    default:
        break;
    }
}
void Presenter::TransferHandler(FinanceStorage* src, int index) {
    UI->Display(SelectionMenu());
    UI->Display("Выберите копилку > ");
    char point = UI->Read();
    int i = -1;
    if (isdigit(point)) {
        i = point - '0';
    }
    if (i >= 0 && i < Storages->size() && i != index) {
        UI->Display("Введите сумму для перевода > ");
        FinanceStorage* dst = Storages->at(index);
        double amount = std::stod(UI->ReadLine());
        if (src->Transfer(amount, dst)) {
            UI->Display("Операция завершена\n");
        } else {
            UI->Display("Операция не завершена\n");
        }
    }
}
void Presenter::RefillHandler(FinanceStorage* dst, int index)
{
    UI->Display(SelectionMenu());
    UI->Display("Выберите копилку > ");
    char point = UI->Read();
    int i = -1;
    if (isdigit(point)) {
        i = point - '0';
    }
    if (i >= 0 && i < Storages->size() && i != index) {
        UI->Display("Введите сумму для пополнения > ");
        FinanceStorage* src = Storages->at(index);
        double amount = std::stod(UI->ReadLine());
        if (dst->Refill(amount, src)) {
            UI->Display("Операция завершена\n");
        } else {
            UI->Display("Операция не завершена\n");
        }
    }
}