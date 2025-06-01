#include "functions.h"
#include "errors.h"
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Считывает все строки из указанного файла.
 * @param fileName Путь к файлу для чтения.
 * @return Вектор строк: каждая строка файла как отдельный элемент.
 * @throws Error при невозможности открыть файл.
 */
std::vector<std::string> readLinesFromFile(const std::string& fileName) {
    std::ifstream file(fileName); ///< Открываю файл на чтение
    if (!file.is_open()) {
        throw Error(ErrorType::inFileNotExist, "", fileName); ///< Ошибка: файл не найден или не открыт
    }

    std::vector<std::string> lines; ///< Результат: строки файла
    std::string line;
    while (std::getline(file, line)) { ///< Читаю построчно
        lines.push_back(line); ///< Добавляю строку в вектор
    }
    return lines;
}
