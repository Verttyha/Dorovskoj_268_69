#include "functions.h"
#include "errors.h"
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Преобразует строки текста в матрицу целых чисел.
 *
 * Каждая строка должна содержать числа, разделённые пробелами.
 * Пустые строки пропускаются.
 *
 * @param lines Вектор строк, каждая из которых представляет собой строку матрицы.
 * @return Двумеренный вектор целых чисел — полученная матрица.
 * @throws Error при неверном формате данных или если матрица не прямоугольная.
 */
std::vector<std::vector<int>> parseMatrixFromLines(const std::vector<std::string>& lines) {
    if (lines.empty()) {
        throw Error(ErrorType::emptyFile);
    }

    std::vector<std::vector<int>> matrix;
    int expectedCols = -1; ///< Количество столбцов, ожидаемое во всех строках


    for (const auto& line : lines) {
        if (line.empty()) {
            throw Error(ErrorType::emptyLine);
        }

        std::istringstream iss(line); ///< Разбираю строку на числа
        std::vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value); ///< Добавляю значение в строку
        }

        if (iss.fail() && !iss.eof()) {
            throw Error(ErrorType::invalidSymbol, "Неверный формат числа", ""); ///< Ошибка: нечисловой символ
        }

        if (expectedCols < 0) {
            expectedCols = static_cast<int>(row.size()); ///< Запоминаю количество столбцов в первой строке
        }

        if (row.empty() || static_cast<int>(row.size()) != expectedCols) {
            throw Error(ErrorType::notRectangular, "Неправильное число столбцов", ""); ///< Ошибка: строки разной длины
        }

        matrix.push_back(row); ///< Добавляю строку в матрицу
    }

    return matrix;
}