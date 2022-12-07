#pragma once
#include "FinanceStorage.h"
#include "../exceptions/WrongCardNumberException.h"

enum class EBankCardType
{
    Debit,
    Credit
};

class BankCard : public FinanceStorage
{
    private:
        EBankCardType Type;
        std::string CardNumber;
        bool IsCardNumberCorrect(std::string cardNumber);

    public:
        BankCard(EBankCardType type, std::string cardNumber, std::string name, std::string comment, double balance);
        std::string ToString() override;
        bool Equals(FinanceStorage* another) override;
};