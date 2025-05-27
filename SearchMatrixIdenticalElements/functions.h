#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
#include "errors.h"

/// @brief Структура, описывающая прямоугольную подматрицу.
struct Rectangle {
    int rowStart; ///< Индекс начальной строки (верхняя граница).
    int colStart; ///< Индекс начального столбца (левая граница).
    int rowEnd;   ///< Индекс конечной строки (нижняя граница).
    int colEnd;   ///< Индекс конечного столбца (правая граница).
    int size;     ///< Площадь подматрицы (rows × cols).
};

/// @brief Проверяет размеры и форму матрицы (прямоугольность, ограничения).
/// @param matrix Двумерный вектор целых чисел.
/// @param maxSize Максимально допустимое количество строк/столбцов.
/// @return true, если матрица валидна.
bool isValidMatrix(const std::vector<std::vector<int>>& matrix, int maxSize);

/// @brief Считывает все строки из текстового файла.
/// @param filename Путь к входному файлу.
/// @return Вектор строк из файла.
/// @throws Error с типом ErrorType::inFileNotExist при неудаче открытия.
std::vector<std::string> readLinesFromFile(const std::string& filename);

/// @brief Преобразует строки в числовую матрицу.
/// @param lines Вектор строк, каждая строка — строка матрицы.
/// @return Матрица как вектор векторов.
/// @throws Error при ошибке формата, пустых строках, недопустимых символах.
std::vector<std::vector<int>> parseMatrixFromLines(const std::vector<std::string>& lines);

/// @brief Объединяет чтение строк и парсинг матрицы из файла.
/// @param filename Имя файла.
/// @param matrix Ссылка на матрицу для записи результата.
/// @throws Error — ошибки чтения, парсинга или структуры.
void readMatrixFromFile(const std::string& filename, std::vector<std::vector<int>>& matrix);

/// @brief Записывает матрицу в текстовый файл.
/// @param filename Имя файла.
/// @param matrix Матрица для записи.
/// @throws Error с типом ErrorType::outFileCreateFail при ошибке открытия.
void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix);

/// @brief Находит наибольшую по площади подматрицу с одинаковыми элементами.
/// @param matrix Исходная матрица.
/// @return Структура Rectangle, описывающая найденную подматрицу.
Rectangle findMaxIdenticalSubmatrix(const std::vector<std::vector<int>>& matrix);

#endif // FUNCTIONS_H
