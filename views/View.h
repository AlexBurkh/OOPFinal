#pragma once
#include <string>
#include <iostream>

class View
{
public:
    virtual void Display(std::string) = 0;
    virtual std::string ReadLine() = 0;
    virtual char Read() = 0;
};
