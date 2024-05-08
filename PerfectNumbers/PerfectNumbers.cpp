#include <iostream>
#include <locale>

// Функция для проверки, является ли число совершенным
bool isPerfectNumber(__int64 num) {
    __int64 sum = 0;
    for (__int64 i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num && num != 0;
}

int main() {
    int start, end;

    // Установка локали для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    // Запросить пользовательский ввод диапазона чисел
    std::cout << "Введите начало диапазона: ";
    std::cin >> start;
    std::cout << "Введите конец диапазона: ";
    std::cin >> end;

    // Проверка введенных данных
    if (start > end) {
        std::cout << "Начальный диапазон должен быть меньше или равен конечному." << std::endl;
        return 1; // Завершение программы с кодом ошибки
    }

    // Перебор чисел в заданном диапазоне и поиск совершенных чисел
    for (int i = start; i <= end; ++i) {
        if (isPerfectNumber(static_cast<__int64>(i))) {
            std::cout << i << " - совершенное число" << std::endl;
        }
    }

    return 0;
}
