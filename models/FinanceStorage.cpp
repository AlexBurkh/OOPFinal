#include "FinanceStorage.h"

bool FinanceStorage::Equals(FinanceStorage* another)
{
    return (this->Name == another->Name) && (this->Balance == another->Balance) && (this->Comment == another->Comment);
}

std::string FinanceStorage::ToString()
{
    return "Название: \"" + this->Name + "\" Комментарий: \"" + this->Comment + "\" Баланс: \"" + BalanceToString(Balance) + "\"";
}

bool FinanceStorage::Add(double amount)
{
    if (amount > 0) {
        this->Balance += amount;
        return true;
    }
    return false;
}

double FinanceStorage::Get(double amount) 
{
    if ((amount > 0) && (amount <= this->Balance)) {
        this->Balance -= amount;
        return amount;
    }
    return 0;
}

bool FinanceStorage::Transfer(double amount, FinanceStorage* dst)
{
    double taken = this->Get(amount);
    if (taken > 0) {
        return dst->Add(taken);
    }
    return false;
}

bool FinanceStorage::Refill(double amount, FinanceStorage* src)
{
    double taken = src->Get(amount);
    if (taken > 0) {
        return this->Add(taken);
    }
    return false;
}

double FinanceStorage::GetBalance()
{
    return Balance;
}