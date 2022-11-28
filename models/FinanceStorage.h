#pragma once
#include <string>

/// @brief Базовый класс, реализующий функционал взаимодействия между счетами
class FinanceStorage 
{
    protected:
        // Fields
        std::string Name;
        std::string Comment;
        double Balance;

        // Methods
        bool Add(double amount);
        double Get(double amount);

    public:
        /// @brief Выполняет перевод средств из текущего объекта в переданный по указателю
        /// @param amound Сумма средств для перевода
        /// @param dst Счет - адресат для перевода
        /// @return Возвращает статус операции
        bool Transfer(double amound, FinanceStorage* dst);
        /// @brief Пополняет средства в текущий объект из переданного по указателю
        /// @param amount Сумма средств для перевода
        /// @param src Счет - источник средств для перевода
        /// @return Возвращает статус операции
        bool Refill(double amount, FinanceStorage* src);
        /// @brief Определяет равен ли текущий объект переданному в параметрах
        /// @param another Объект для сравнения
        /// @return Возвращает результат сравнения
        virtual bool Equals(FinanceStorage* another);
        /// @brief Текстовое представление объекта
        /// @return Возвращает представление типа std::string
        virtual std::string ToString();
};

/// @brief Проверяет ли текущий объект экземляром класса, переданного в шаблонном параметре
/// @tparam T Класс для проверки принадлежности текущего объекта
/// @param ptr Объект для проверки принадлежности
/// @return Возвращает объект операции
template <typename T>
inline bool instanceof(FinanceStorage* ptr) 
{
   return dynamic_cast<T*>(ptr) != nullptr;
}

inline std::string BalanceToString(double balance) 
{
    auto str = std::to_string(balance);
    int dotIndex = str.find('.');
    auto fraction = str.substr(dotIndex + 1);
    int symbForDeleteFromEnd = 0;
    for (size_t i = fraction.size() - 1; i != 0; --i)
    {
        char s = fraction[i];
        if (s == '0') {
            symbForDeleteFromEnd++;
        }
        else {
            break;
        }
    }
    return str.substr(0, dotIndex + fraction.size() - symbForDeleteFromEnd + 1);
    
}