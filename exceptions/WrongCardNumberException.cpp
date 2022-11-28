#include "WrongCardNumberException.h"

const char * WrongCardNumberException::what()
{  
    return "Попытка создания карты с некорректным номером\n";  
}  