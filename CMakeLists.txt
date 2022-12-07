cmake_minimum_required(VERSION 3.16)
project(HomeFinance)

set(CMAKE_CXX_STANDARD 14)

add_executable(HomeFinance Program.cpp models/FinanceStorage.cpp models/BankCard.cpp models/Envelope.cpp presenter/Presenter.cpp views/View.cpp views/ConsoleView.cpp exceptions/WrongCardNumberException.cpp)
