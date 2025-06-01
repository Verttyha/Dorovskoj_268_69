#include "functions.h"
#include "errors.h"
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief Записывает матрицу целых чисел в файл.
 *
 * Каждый ряд матрицы выводится на отдельной строке, элементы разделяются пробелами.
 *
 * @param matrix Двумеренный вектор целых чисел для записи.
 * @param filename Путь к выходному файлу.
 * @throws Error при невозможности открыть или записать файл.
 */
void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix) {
    std::ofstream file(filename); ///< Открываю файл на запись
    if (!file.is_open()) {
        throw Error(ErrorType::outFileCreateFail, "", filename); ///< Ошибка: не удалось открыть файл
    }

    for (const auto& row : matrix) {
        for (std::size_t j = 0; j < row.size(); ++j) {
            file << row[j]; ///< Записываю элемент
            if (j + 1 < row.size()) {
                file << ' '; ///< Разделяю пробелом, кроме последнего
            }
        }
        file << '\n'; ///< Завершаю строку
    }
}