#ifndef ERRORS_H
#define ERRORS_H

#include <string>

/// @brief Типы ошибок, возникающих при работе с матрицей.
enum class ErrorType {
    noError,                ///< Ошибок не обнаружено.
    inFileExtensionError,   ///< Расширение файла не соответствует «.txt».
    emptyFile,              ///< Входной файл не содержит матрицу.
    inFileNotExist,         ///< Файл не найден или не удалось открыть входной файл.
    outFileCreateFail,      ///< Ошибка при создании выходного файла (нет прав или директории не существует).
    matrixSizeExceed,       ///< Размер матрицы превышает допустимое значение (>20).
    invalidSymbol,          ///< Обнаружен недопустимый символ в матрице.
    outOfRange,             ///< Значение элемента выходит за допустимые границы типа int.
    emptyLine,              ///< Найдена пустая строка в матрице.
    notRectangular          ///< Строки матрицы имеют разную длину (матрица не прямоугольная).
};

/// @brief Исключение для представления ошибок при работе с файлами и матрицей.
class Error {
public:
    ErrorType type;         ///< Тип ошибки.
    std::string details;    ///< Дополнительная информация об ошибке.
    std::string filePath;   ///< Путь к файлу, вызвавшему ошибку.

    /**
     * @brief Конструктор ошибки.
     * @param t    Тип ошибки.
     * @param det  Дополнительные сведения (необязательно).
     * @param file Путь к файлу (если применимо).
     */
    Error(ErrorType t, const std::string& det = "", const std::string& file = "")
        : type(t), details(det), filePath(file) {}

    /**
     * @brief Генерирует человекочитаемое сообщение об ошибке.
     * @return Строка с описанием ошибки и, при наличии, дополнительными сведениями.
     */
    std::string generateErrorMessage() const {
        std::string msg;
        switch (type) {
        case ErrorType::inFileExtensionError:
            msg = "Расширение файла не соответствует \".txt\".";
            break;
        case ErrorType::emptyFile:
            msg = "Входной файл пуст и не содержит матрицу.";
            break;
        case ErrorType::inFileNotExist:
            msg = "Не удалось открыть входной файл: " + filePath + ".";
            break;
        case ErrorType::outFileCreateFail:
            msg = "Не удалось создать или записать в выходной файл: " + filePath + ".";
            break;
        case ErrorType::matrixSizeExceed:
            msg = "Размер матрицы превышает допустимый лимит (>20).";
            break;
        case ErrorType::invalidSymbol:
            msg = "Обнаружен недопустимый символ в матрице.";
            break;
        case ErrorType::outOfRange:
            msg = "Значение элемента выходит за границы типа int.";
            break;
        case ErrorType::emptyLine:
            msg = "Найдена пустая строка в матрице.";
            break;
        case ErrorType::notRectangular:
            msg = "Строки матрицы имеют разную длину (матрица не прямоугольная).";
            break;
        case ErrorType::noError:
            msg = "Ошибок не обнаружено.";
            break;
        }
        if (!details.empty()) {
            msg += " Дополнительно: " + details + ".";
        }
        return msg;
    }
};

#endif // ERRORS_H
