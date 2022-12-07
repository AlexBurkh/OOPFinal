#include "BankCard.h"

BankCard::BankCard(EBankCardType type, std::string cardNumber, std::string name, std::string comment, double balance)
{
    this->Type = type;
    this->CardNumber = cardNumber;
    this->CardNumber = cardNumber;
    this->Name = name;
    this->Comment = comment;
    this->Balance = balance;
}

std::string BankCard::ToString() 
{
    std::string cardType = "";
    if (this->Type == EBankCardType::Credit) {
        cardType = "Кредитная карта";
    } else if (this->Type == EBankCardType::Debit) {
        cardType = "Дебетовая карта";
    }

    return "{ Тип: \"" + cardType + "\" Номер карты: \"" + this->CardNumber + "\" " + FinanceStorage::ToString() + " }\n";
}

bool BankCard::Equals(FinanceStorage* another)
{
    if (another != nullptr && instanceof<BankCard>(another)) {
        BankCard* bc = dynamic_cast<BankCard*>(another);
        return (Type == bc->Type) && (CardNumber == bc->CardNumber);
    }
    return false;
}

bool BankCard::IsCardNumberCorrect(std::string cardNumber)
{
    constexpr char delimiter = ' ';
    constexpr int spaceIndex = 4;
    constexpr int groupLength = 4;

    int pos = 0;
    std::string group = "";
    bool groups[4] { false, false, false, false };

    while ((pos < cardNumber.size()) && (group = cardNumber.substr(pos)).size()) {
        if (group.find(delimiter) == spaceIndex) {
            groups[pos % groupLength] = true;
            pos += (spaceIndex + 1);
        }
        else {
            if (group.size() == groupLength) {
                groups[3] = true;
                break;
            }
        }
    }
    bool flag = true;
    for (bool f : groups) {
        flag & f;
    }
    return flag;
}