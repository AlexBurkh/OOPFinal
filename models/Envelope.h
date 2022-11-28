#pragma once
#include "FinanceStorage.h"

class Envelope : public FinanceStorage
{
    public:
        Envelope(std::string name, std::string comment, double blanace);
        std::string ToString();
        bool Equals(FinanceStorage* another) override;
};