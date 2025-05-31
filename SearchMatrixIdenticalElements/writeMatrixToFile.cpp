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

}