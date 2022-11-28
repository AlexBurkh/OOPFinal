#pragma once
#include <exception> 

class WrongCardNumberException : public std::exception 
{  
    public:  
        const char * what();
};  