#include "functions.h"
#include "errors.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * @mainpage SearchMatrixIdenticalElements Documentation
 *
 * Эта программа предназначена для поиска максимальной подматрицы одинаковых элементов в известной матрице с данными параметрами размеров.
 *
 * Наименование программы: SearchMatrixIdenticalElements.
 * Программа написана на языке C++.
 *
 * ## Заголовочные файлы
 * - @ref errors.h — перечисление ErrorType и класс Error для генерации сообщений об ошибках.
 * - @ref functions.h — структура Rectangle и объявления функций для работы с матрицей: чтение, парсинг, валидация, запись, поиск подматрицы.
 *
 * ## Исходные файлы
 * - @ref main.cpp — точка входа в программу.
 * - @ref findMaxIdenticalSubmatrix.cpp — функция по поиску наибольшей подматрицы максимальных элементов.
 * - @ref isValidMatrix.cpp — функция для проверки, что матрица корректная, все строки имеют одинаковое количество столбцов.
 * - @ref parseMatrixFromLines.cpp — функция преобразования строк в матрицу.
 * - @ref readLinesFromFile.cpp — функция по считыванию строк из файла.
 * - @ref readMatrixFromFile.cpp — функция по считыванию файла и созданию на его основе матрицы.
 * - @ref writeMatrixToFile.cpp — функция по записи матрицы в файл.
 *
 * См. также разделы "Files" и "Classes" для подробной информации.
 */


/**
 * @brief Точка входа в программу.
 *
 * Читает имена входного и выходного файлов, затем:
 * - считывает матрицу из входного файла;
 * - ищет максимально большую одинаковую подматрицу;
 * - записывает результат в выходной файл.
 *
 * При ошибках выводит сообщение и завершает программу.
 *//**
 * @brief Точка входа в программу.
 * 
 * Выполняет чтение входного файла с матрицей, проверку корректности аргументов, 
 * поиск максимальной подматрицы с одинаковыми элементами, запись результата в выходной файл
 * и обработку исключений.
 * 
 * @param argc Количество аргументов командной строки (должно быть 3).
 * @param argv Массив аргументов командной строки: 
 *            argv[1] — путь к входному файлу (.txt),
 *            argv[2] — путь к выходному файлу.
 * @return int Код завершения программы: 0 — успех, 1 — ошибка.
 */
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    try {
        if (argc != 3) {
            cerr << "Некорректное число параметров." << endl;
            return 1;
        }

        string inputFile = argv[1];
        string outputFile = argv[2];

        // Проверка расширения входного файла
        size_t pos = inputFile.find_last_of(".");
        if (pos == string::npos || inputFile.substr(pos) != ".txt") {
            throw Error(ErrorType::inFileExtensionError);
        }

        vector<vector<int>> matrix;
        readMatrixFromFile(inputFile, matrix);

        // Проверка размеров и формы матрицы
        if (!isValidMatrix(matrix, 20)) {
            throw Error(ErrorType::matrixSizeExceed);
        }

        // Поиск максимальной подматрицы с одинаковыми элементами
        Rectangle maxRect = findMaxIdenticalSubmatrix(matrix);

        // Формирование результата — извлечение найденной подматрицы
        vector<vector<int>> result;
        for (int i = maxRect.rowStart; i <= maxRect.rowEnd; ++i) {
            vector<int> row;
            for (int j = maxRect.colStart; j <= maxRect.colEnd; ++j) {
                row.push_back(matrix[i][j]);
            }
            result.push_back(row);
        }

        writeMatrixToFile(outputFile, result);
    }
    catch (const Error& err) {
        cout << err.generateErrorMessage() << endl;
        return 1;
    }
    return 0;
}
