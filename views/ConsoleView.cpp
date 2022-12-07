#include "ConsoleView.h"

ConsoleView::ConsoleView() 
{

}

void ConsoleView::Display(std::string textToDisplay)
{
    std::cout << textToDisplay;
}

std::string ConsoleView::ReadLine()
{
    std::string input = "";
    while (input == "") {
        std::getline(std::cin, input);
    }
    return input;
}

char ConsoleView::Read()
{
    char input = ' ';
    std::cin >> input;
    return input;
}