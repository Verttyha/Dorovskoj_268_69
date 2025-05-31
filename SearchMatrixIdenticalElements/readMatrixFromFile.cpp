#include "functions.h"
#include "errors.h"
#include <vector>
#include <string>

/**
 * @brief Считывает и проверяет матрицу целых чисел из файла.
 *
 * @param filename Путь к входному файлу.
 * @param matrix  Результирующая матрица.
 * @throws Error при ошибках чтения, парсинга или некорректной структуры.
 */
void readMatrixFromFile(const std::string& filename, std::vector<std::vector<int>>& matrix) {
    auto lines = readLinesFromFile(filename);
    matrix = parseMatrixFromLines(lines);
}