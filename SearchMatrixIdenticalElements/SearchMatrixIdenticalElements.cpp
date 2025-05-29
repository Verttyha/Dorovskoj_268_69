#include <vector>
#include <string>
#include <iostream>

/// @brief Структура, описывающая прямоугольную подматрицу.
struct Rectangle {
    int rowStart; ///< Индекс начальной строки (верхняя граница).
    int colStart; ///< Индекс начального столбца (левая граница).
    int rowEnd;   ///< Индекс конечной строки (нижняя граница).
    int colEnd;   ///< Индекс конечного столбца (правая граница).
    int size;     ///< Площадь подматрицы (rows × cols).
};

// Заглушка isValidMatrix
bool isValidMatrix(const std::vector<std::vector<int>>& matrix, int maxSize) {
    return true;
}

// Заглушка parseMatrixFromLines
std::vector<std::vector<int>> parseMatrixFromLines(const std::vector<std::string>& lines) {
    return {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
}

// Заглушка findMaxIdenticalSubmatrix
Rectangle findMaxIdenticalSubmatrix(const std::vector<std::vector<int>>& matrix) {
    Rectangle maxRect = { 0, 0, 0, 0, 1 };

    return maxRect;
}
int main() {
    return 0;
}
