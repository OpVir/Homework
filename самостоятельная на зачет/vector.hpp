#pragma once

// Подключение необходимых библиотек
#include <fstream>  // Для работы с файлами (ifstream)
#include <ostream>  // Для работы с выходными потоками (ostream)
#include <iostream> // Для работы с вводом/выводом (cin, cout)

namespace home {

    // Структура для представления вектора
    struct Vector {
        double* p; // Указатель на динамический массив
        int n;     // Размер динамического массива

    };

    // Структура для результата чтения вектора
    struct Input {
        bool a; // true, если файл был успешно прочитан
        Vector v; // Прочитанный вектор
    };

    // Структура для результата скалярного произведения
    struct Result {
        bool a; // true, если размеры векторов одинаковые
        double scalar; // Значение скалярного произведения
    };

    // Функция для чтения вектора из файла
    Input read(char const* path);
    
    // Операторы для ввода/вывода векторов
    std::ifstream& operator>>(std::ifstream& ifs, Vector& v);
    std::ostream& operator<<(std::ostream& out, Vector const& v);

    std::istream& operator>>(std::istream& in, Vector& v);
    std::ostream& operator<<(std::ostream& out, Vector const& v);

    // Функция для вычисления скалярного произведения
    Result dotProduct(Vector const& v1, Vector const& v2);
    
    // Перегрузка оператора * для вычисления скалярного произведения
    Result operator*(Vector const& v1, Vector const& v2);

} // namespace home

// Реализация функции чтения вектора из файла
home::Input home::read(char const* path) {
    std::ifstream ifs(path); // Открываем файл для чтения

    if (!ifs.is_open()) { // Проверяем, удалось ли открыть файл
        return { false }; // Возвращаем результат с ошибкой
    }

    Vector v; // Создаем вектор для хранения данных
    
    ifs >> v; // Читаем данные из файла

    return { true, v }; // Возвращаем успешный результат и считанный вектор
}

// Реализация оператора ввода вектора из файла
std::ifstream& home::operator>>(std::ifstream& ifs, Vector& v) {
    ifs >> v.n; // Считываем размер вектора
    v.p = new double[v.n]; // Выделяем память для массива

    for (int i = 0; i < v.n; i++) { // Считываем элементы вектора
        ifs >> v.p[i];
    }

    return ifs; // Возвращаем поток для цепочного вызова
}

// Реализация оператора вывода вектора в поток
std::ostream& home::operator<<(std::ostream& out, Vector const& v) {
    for (int i = 0; i < v.n; i++) { // Проходим по элементам вектора
        out << v.p[i] << ' '; // Выводим каждый элемент с пробелом
    }
    return out; // Возвращаем поток для цепочного вызова
}

// Реализация оператора ввода вектора из стандартного ввода (терминала)
std::istream& home::operator>>(std::istream& in, Vector& v) {
    std::cout << "Enter the size of the vector: "; // Запрашиваем размер вектора
    in >> v.n; // Считываем размер

    v.p = new double[v.n]; // Выделяем память для массива
    std::cout << "Enter the elements of the vector: "; // Запрашиваем элементы
    
    for (int i = 0; i < v.n; i++) { // Считываем элементы вектора
        in >> v.p[i];
    }

    return in; // Возвращаем поток для цепочного вызова
}

// Функция для вычисления скалярного произведения двух векторов
home::Result home::dotProduct(Vector const& v1, Vector const& v2) {
    if (v1.n != v2.n) { // Проверяем, одинаковы ли размеры векторов
        return { false }; // Если нет, возвращаем результат с ошибкой
    }

    double scal = 0; // Переменная для хранения результата скалярного произведения

    for (int i = 0; i < v1.n; i++) { // Проходим по элементам векторов
        scal += v1.p[i] * v2.p[i]; // Считаем скалярное произведение
    }

    return { true, scal }; // Возвращаем успешный результат и значение скалярного произведения
}

// Перегрузка оператора * для вычисления скалярного произведения двух векторов
home::Result home::operator*(Vector const& v1, Vector const& v2) {
    return dotProduct(v1, v2); // Вызываем функцию dotProduct
}
