#include "vector.hpp" // Подключение заголовка с определением векторов
#include <iostream>   // Для работы с вводом/выводом
#include <cstdlib>    // Для system

int main() {
    using namespace home; // Используем пространство имен home

    Vector v; // Создаем переменную для хранения вектора

    // Чтение вектора из файла
    Input in = read("vector.txt");
    
    if (in.a) { // Если файл был успешно прочитан
        v = in.v; // Сохраняем считанный вектор
    } else {
        std::cout << "Unable to read vector values from file." << std::endl;
        
        // Если чтение из файла не удалось, запрашиваем ввод с терминала
        std::cin >> v; // Используем перегруженный оператор ввода
    }

    std::cout << "Vector: " << v << std::endl; // Используем перегруженный оператор вывода

    // Запрашиваем второй вектор для скалярного произведения
    Vector v2;
    std::cout << "Enter the second vector: ";
    std::cin >> v2; // Используем перегруженный оператор ввода для второго вектора

    Result res = v * v2; // Вычисляем скалярное произведение двух векторов
    
    if (res.a) { // Проверяем успешность операции
        std::cout << "Dot product: " << res.scalar << std::endl; // Выводим результат скалярного произведения
    } else {
        std::cout << "Vectors have different sizes!" << std::endl; // Сообщаем о различии размеров векторов
    }

    std::system("pause"); // Ожидаем нажатия клавиши перед завершением программы
    return 0; // Завершаем программу с кодом 0 (успешно)
}