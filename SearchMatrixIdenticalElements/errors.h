#ifndef ERRORS_H
#define ERRORS_H

#include <string>

/// @brief ���� ������, ����������� ��� ������ � ��������.
enum class ErrorType {
    noError,                ///< ������ �� ����������.
    inFileExtensionError,   ///< ���������� ����� �� ������������� �.txt�.
    emptyFile,              ///< ������� ���� �� �������� �������.
    inFileNotExist,         ///< ���� �� ������ ��� �� ������� ������� ������� ����.
    outFileCreateFail,      ///< ������ ��� �������� ��������� ����� (��� ���� ��� ���������� �� ����������).
    matrixSizeExceed,       ///< ������ ������� ��������� ���������� �������� (>20).
    invalidSymbol,          ///< ��������� ������������ ������ � �������.
    outOfRange,             ///< �������� �������� ������� �� ���������� ������� ���� int.
    emptyLine,              ///< ������� ������ ������ � �������.
    notRectangular          ///< ������ ������� ����� ������ ����� (������� �� �������������).
};

/// @brief ���������� ��� ������������� ������ ��� ������ � ������� � ��������.
class Error {
public:
    ErrorType type;         ///< ��� ������.
    std::string details;    ///< �������������� ���������� �� ������.
    std::string filePath;   ///< ���� � �����, ���������� ������.

    /**
     * @brief ����������� ������.
     * @param t    ��� ������.
     * @param det  �������������� �������� (�������������).
     * @param file ���� � ����� (���� ���������).
     */
    Error(ErrorType t, const std::string& det = "", const std::string& file = "")
        : type(t), details(det), filePath(file) {}

    /**
     * @brief ���������� ���������������� ��������� �� ������.
     * @return ������ � ��������� ������ �, ��� �������, ��������������� ����������.
     */
    std::string generateErrorMessage() const {
        std::string msg;
        switch (type) {
        case ErrorType::inFileExtensionError:
            msg = "���������� ����� �� ������������� \".txt\".";
            break;
        case ErrorType::emptyFile:
            msg = "������� ���� ���� � �� �������� �������.";
            break;
        case ErrorType::inFileNotExist:
            msg = "�� ������� ������� ������� ����: " + filePath + ".";
            break;
        case ErrorType::outFileCreateFail:
            msg = "�� ������� ������� ��� �������� � �������� ����: " + filePath + ".";
            break;
        case ErrorType::matrixSizeExceed:
            msg = "������ ������� ��������� ���������� ����� (>20).";
            break;
        case ErrorType::invalidSymbol:
            msg = "��������� ������������ ������ � �������.";
            break;
        case ErrorType::outOfRange:
            msg = "�������� �������� ������� �� ������� ���� int.";
            break;
        case ErrorType::emptyLine:
            msg = "������� ������ ������ � �������.";
            break;
        case ErrorType::notRectangular:
            msg = "������ ������� ����� ������ ����� (������� �� �������������).";
            break;
        case ErrorType::noError:
            msg = "������ �� ����������.";
            break;
        }
        if (!details.empty()) {
            msg += " �������������: " + details + ".";
        }
        return msg;
    }
};

#endif // ERRORS_H
