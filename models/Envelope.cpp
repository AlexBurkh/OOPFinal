#include "Envelope.h"

Envelope::Envelope(std::string name, std::string comment, double balance)
{
    this->Name = name;
    this->Comment = comment;
    this->Balance = balance;
}

std::string Envelope::ToString()
{
    return "{ Тип: \"Конверт\" " + FinanceStorage::ToString() + " }\n";
}

bool Envelope::Equals(FinanceStorage* another)
{
    if (another != nullptr && instanceof<Envelope>(another))
    {
        Envelope* env = dynamic_cast<Envelope*>(another);
        return (Name == env->Name) && (Comment == env->Comment) && (Balance = env->Balance);
    }
    return false;
}