#include "functions.h"
#include <vector>


/**
 * @brief Проверяет, является ли заданная матрица корректной (не пустая и все строки имеют одинаковое число столбцов).
 * @param matrix Двумеренный вектор целых чисел, представляющий матрицу.
 * @return true, если матрица корректна; false — в противном случае.
 */

bool isValidMatrix(const std::vector<std::vector<int>>& matrix, int maxSize) {
    if (matrix.empty()) {
        return false;  ///< Матрица пуста — некорректна.
    }
    if (static_cast<int>(matrix.size()) > maxSize) {
        return false;  ///< Число строк превышает допустимый предел.
    }

    std::size_t numCols = matrix[0].size();  ///< Количество столбцов в первой строке.
    if (numCols == 0 || static_cast<int>(numCols) > maxSize) {
        return false;  ///< Нулевая ширина или превышение максимума — матрица некорректна.
    }

    for (const auto& row : matrix) {
        if (row.size() != numCols) {
            return false;  ///< Найдена строка с отличным числом столбцов — матрица некорректна.
        }
    }

    return true;  ///< Все проверки пройдены — матрица корректна.
}